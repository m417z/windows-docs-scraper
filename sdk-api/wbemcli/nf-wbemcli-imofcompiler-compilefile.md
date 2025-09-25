# IMofCompiler::CompileFile

## Description

The **IMofCompiler::CompileFile** method compiles a MOF file (including
binary MOFs) and stores the information in the
[WMI repository](https://learn.microsoft.com/windows/desktop/WmiSdk/gloss-w).
This method performs the same operation as the [Mofcomp](https://learn.microsoft.com/windows/desktop/WmiSdk/mofcomp)
command.

## Parameters

### `FileName` [in]

The name of the file to be compiled.

### `ServerAndNamespace` [in]

The path to the default namespace where any classes or instance are written.

You can specify a namespace on a remote computer ("\\computer\root", for
example). This value can be overridden by the **#pragma** command and should not be used if
auto recovery is desired. If **NULL**, then the root\default namespace on the local
computer is the default.

### `User` [in]

A value that specifies the credentials used to compile on remote computers. If the value is
**NULL**, the user context is whatever the calling process is using. This is always
ignored when connecting to the local computer. For more information, see the Remarks section.

### `Authority` [in]

A value that specifies the credentials for compiling on remote computers. If the value is
**NULL**, the authority context is whatever the calling process is using. This is always
ignored when connecting to the local computer. For more information, see the Remarks section.

### `Password` [in]

A value that specifies the credentials for compiling on remote computers. If the value is **NULL**, the password of the current context is used. This is always ignored when connecting to the local computer.

### `lOptionFlags` [in]

A parameter that, when the
**CompileFile** method is used, enables the combination of one or more of the following flags.

#### WBEM_FLAG_CHECK_ONLY

Performs only a syntax check.

#### WBEM_FLAG_AUTORECOVER

If the method is successful, adds the name of the file to the list of files to be compiled during automatic database recovery.

Be aware that this flag cannot be combined with either the namespace, class, or instance flags.

#### WBEM_FLAG_CONSOLE_PRINT

Sends various useful messages to the console.

#### WBEM_FLAG_DONT_ADD_TO_LIST

Prevents the file from being added to the list of files compiled during automatic database recovery.

This flag is not compatible with **WBEM_FLAG_AUTORECOVER**.

### `lClassFlags` [in]

The flags that control the creation of classes.

Parameters may be 0 or a combination of the following values.

#### WBEM_FLAG_UPDATE_ONLY

Prevents creation of a class.

You can combine this flag with either **WBEM_FLAG_UPDATE_SAFE_MODE** or **WBEM_FLAG_UPDATE_FORCE_MODE**.

#### WBEM_FLAG_CREATE_ONLY

Allows only class creation.

You may not combine this flag with the other flags.

#### WBEM_FLAG_UPDATE_SAFE_MODE

Updates the class unless conflicts exist.

You may combine this flag with **WBEM_FLAG_UPDATE_ONLY**.

#### WBEM_FLAG_UPDATE_FORCE_MODE

Updates and resolves conflicts wherever possible. Using force mode to update a static class results in the deletion of all instances of that class. Force update on a provider class does not delete instances of the class.

You may combine this flag with *llnstanceFlags*.

### `lInstanceFlags` [in]

The flags that control the creation of instances.

Parameter values can be either 0 or one of the following flags.

#### WBEM_FLAG_UPDATE_ONLY

Only allow updates.

#### WBEM_FLAG_CREATE_ONLY

Allow only new instances.

### `pInfo` [in, out]

Pointer to a [WBEM_COMPILE_STATUS_INFO](https://learn.microsoft.com/windows/win32/api/wbemcli/ns-wbemcli-wbem_compile_status_info) that describes an error.

If the parameter value is not **NULL**, an error has occurred, and the structure is filled with error information.

## Return value

This method can return one of these values.

2

Warning that [#pragma autorecover](https://learn.microsoft.com/windows/desktop/WmiSdk/pragma-autorecover) statement is not present. This statement should be one the first line of the MOF file.

## Remarks

If the *User* parameter is in the form of <*domain\user*>, the *Authority* parameter must be **NULL**.

## See also

[IMofCompiler](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-imofcompiler)

[WBEM_CHANGE_FLAG_TYPE](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_change_flag_type)

[WBEM_COMPILER_OPTIONS](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_compiler_options)

[mofcomp](https://learn.microsoft.com/windows/desktop/WmiSdk/mofcomp)