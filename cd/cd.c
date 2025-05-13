#include "minishell.h"

void	    ft_cd(t_minishell *minishell);
static void	cd_path(t_minishell *minishell, char *arg);
static void cd_error_check(t_minishell *minishell, char *path);
static void	cd_oldpwd(t_minishell *minishell);
static void	cd_home(t_minishell *minishell);
static void	update_pwd(t_minishell *minishell, char *oldpwd);
static void ft_setenv(t_minishell *minishell, const char *env_var, const char *value);
static char	*expand_tilde(t_minishell *minishell, char *arg);

static char	*expand_tilde(t_minishell *minishell, char *arg)
{
    char    *home;
    char    *new_path;

    home = ft_getenv(minishell->envp, "HOME=");
    if (!home)
        return (NULL);
    
    // Si es solo "~", devolver HOME directamente
    if (ft_strcmp(arg, "~") == 0)
    {
        free(arg);
        return (ft_strdup(home));
    }
    
    // Si es "~/" o similar, concatenar
    new_path = ft_strjoin(home, arg + 1); // mas 1 para quitar el coso al concatenar el home con arg
    free(arg);
    return (new_path);
}

static void ft_setenv(t_minishell *minishell, const char *env_var, const char *value)
{
    char *new_var;
    int i;
    int len;
    int env_len;

    len = ft_strlen(env_var); 
    new_var = ft_strjoin(env_var, "="); // enchufarle el = 
    new_var = ft_strjoin(env_var_eq, value); // unir "NAME=" con el valor "NAME=VALUE"
    if (!new_var)
        return;
    // Buscar si la variable ya existe
    i = 0;
    while (minishell->envp[i]) // recorrer las variables de entorno
    {
        env_len = ft_strlen(minishell->envp[i]);
        // Comprobar si el comienzo de la cadena coincide con la variable que estamos buscando
        if (ft_strncmp(minishell->envp[i], env_var, len) == 0 && minishell->envp[i][len] == '=') 
        {
            // Si se encuentra la variable, se reemplaza
            free(minishell->envp[i]);
            minishell->envp[i] = new_var; // Nuevo valor a la variable de entorno
            return ;
        }
        i++;
    }
    // Si se llega aquí es que no se ha encontrao
    minishell->envp[i] = new_var; // Se creala nueva variable
    minishell->envp[i + 1] = NULL;
}

static void	update_pwd(t_minishell *minishell, char *oldpwd)
{
	char	*cwd;
	char	*new_pwd;

	cwd = getcwd(NULL, 0); // donde nos encontramos actualmente
	if (!cwd)
		return ;
	new_pwd = ft_strdup(cwd); //duplicar pa trabajar con la copia
	free(cwd);
	if (!new_pwd)
		return ;
	ft_setenv(minishell, "OLDPWD", oldpwd);
	ft_setenv(minishell, "PWD", new_pwd);
    free(old);
	free(new_pwd);
}

static void	cd_home(t_minishell *minishell)
{
	char	*home;
	char	*oldpwd;

	home = ft_getenv(minishell->envp, "HOME=");
	if (!home || home[0] == '\0')
	{
		printf("minishell: cd: HOME not set\n");
		minishell->exit_status = 1;
		return ;
	}
	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		return ;
	if (chdir(home) == 0)
		update_pwd(minishell, oldpwd);
	else
		print_cd_error(home, "Failed to change directory", minishell);
	free(oldpwd);
}

static void	cd_oldpwd(t_minishell *minishell)
{
	char	*oldpwd;
	char	*current;

	oldpwd = ft_getenv(minishell->envp, "OLDPWD="); //buscarla en las variables de entorno
	if (!oldpwd) // en caso de que no esté
	{
		printf("minishell: cd: OLDPWD not set\n");
		minishell->exit_status = 1;
		return ;
	}
	current = getcwd(NULL, 0); //se guarda el actual pa no perderlo
	if (!current)
		return ;
	if (chdir(oldpwd) == 0)
	{
		update_pwd(minishell, current); //actualizar variables
		printf("%s\n", oldpwd);
	}
	else
		print_cd_error(oldpwd, "Failed to change directory", minishell); //por si peta
	free(current);
}

static void cd_error_check(t_minishell *minishell, char *path) //errores sin más
{
    struct stat info;

    if (access(path, F_OK))
    {
        printf("minishell: cd: %s: No such file or directory\n", path);
        minishell->exit_status = 1;
    }
    else if (stat(path, &info) != 0 || !S_ISDIR(info.st_mode))
    {
        printf("minishell: cd: %s: Not a directory\n", path);
        minishell->exit_status = 1;
    }
    else if (access(path, X_OK))
    {
        printf("minishell: cd: %s: Permission denied\n", path);
        minishell->exit_status = 1;
    }
    else
    {
        printf("minishell: cd: %s: Failed to change directory\n", path);
        minishell->exit_status = 1;
    }
}


static void	cd_path(t_minishell *minishell, char *arg)
{
	char	*path;
	char	*oldpwd;

	path = ft_strdup(arg);
	if (!path)
		return ;
	if (path[0] == '~') //si resulta que es el coso
	{
		path = expand_tilde(minishell, path);
		if (!path)
		{
			printf("minishell: cd: HOME not set\n");
			minishell->exit_status = 1;
			return ;
		}
	}
	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
	{
		free(path);
		return ;
	}
	if (chdir(path) == 0)
		update_pwd(minishell, oldpwd);
	else
		cd_error_check(minishell, path);
	free(oldpwd);
	free(path);
}

void	ft_cd(t_minishell *minishell)
{
	char	*arg;

	if (minishell->args_num > 2)
	{
		printf("minishell: cd: too many arguments\n");
		minishell->exit_status = 150;
		return ;
	}
	if (minishell->args_num == 1)
	{
		cd_home(minishell);
		return ;
	}
	arg = minishell->input_matrix[1]; //mas legible evito hacer una linea muy larga
	if (arg[0] == '-' && arg[1] == '\0') //comprobar que nos pasan "cd -"
		cd_oldpwd(minishell);
	else
		cd_path(minishell, arg);
}