#include "shell.h"

int cd(char *path)
{
    char *home = _getenv("HOME");
    char *oldpwd = _getenv("PWD");
    char *newpwd;
    if (path == NULL || _strcmp(path, "~") == 0) {
        newpwd = home;
    } else if (_strcmp(path, "-") == 0) {
        newpwd = _getenv("OLDPWD");
    } else {
        newpwd = path;
    }
    if (chdir(newpwd) != 0) {
        perror("cd");
        return 1;
    }
    _setenv("OLDPWD", oldpwd);
    _setenv("PWD", newpwd);
    return 0;
}
