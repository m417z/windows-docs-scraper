# IMofCompiler::CreateBMOF

## Description

The **IMofCompiler::CreateBMOF** method creates a binary MOF file. File creation is accomplished by parsing a regular MOF file and storing a binary representation of the classes and instances into a special file format. Typically, this data binary large object (BLOB) is stored as a resource in an executable file, which can later be extracted for a call to the
[CompileBuffer](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-imofcompiler-compilebuffer) method. The **IMofCompiler::CreateBMOF** can also be used to create a localized MOF file (.mfl).

## Parameters

### `TextFileName` [in]

The name of the text file to be parsed.

### `BMOFFileName` [in]

**Binary MOF file:** The name of the file in which the resulting binary MOF data is to be stored.

**Localized MOF file:** The *BMOFFileName* string must contain the following comma-separated values:

* a<locale>

  Specifies the locale information. This value must start with a preceding comma. For more information, see the description of the **-ADMENDMENT** switch for the [mofcomp](https://learn.microsoft.com/windows/desktop/WmiSdk/mofcomp) utility.
* n<filename.mof>

  The name of the file in which the resulting binary MOF data is to be stored.
* l<filename.mfl>

  The name of the file in which the resulting localized MOF data is to be stored.

For example, *BMOFFileName*=",aMS_409,nmyFile.mof,lmyFile.mfl".

### `ServerAndNamespace` [in]

The path of the default namespace, where classes or instances are written.

You can use this parameter to specify a namespace on a remote computer ("\\computer\root", for example). This value may be overridden by the
[#pragma](https://learn.microsoft.com/windows/desktop/WmiSdk/-pragma) command and should not be used if you use autorecovery. If the parameter value is **NULL**, the root\default namespace on the local computer is the default.

### `lOptionFlags` [in]

You can combine one or more of the following flags.

#### WBEM_FLAG_CHECK_ONLY

Performs only a syntax check.

#### WBEM_FLAT_CONSOLE_PRINT

Sends various useful messages to the console.

#### WBEM_FLAG_WMI_CHECK

Performs additional checks on the resulting binary MOF file using the WMIMOFCHK program, which is part of the WMI section of the Windows SDK.

### `lClassFlags` [in]

The flags that control the creation of classes. The parameter value may be 0 or a combination of the following flags.

#### WBEM_FLAG_UPDATE_ONLY

Prevents class creation.

You can combine this flag with either **WBEM_FLAG_UPDATE_SAFE_MODE** or **WBEM_FLAG_UPDATE_FORCE_MODE**.

#### WBEM_FLAG_CREATE_ONLY

Permits only class creation.

You cannot combine this with other flags.

#### WBEM_FLAG_UPDATE_SAFE_MODE

Updates the class unless conflicts exist.

You can combine this flag with **WBEM_FLAG_UPDATE_ONLY**.

#### WBEM_FLAG_UPDATE_FORCE_MODE

Updates and resolves conflicts when possible. Using force mode to update a static class results in the deletion of all instances of that class. Forces an update for a provider class does not delete instances of the class.

You can combine this flag with *lInstanceFlags*.

### `lInstanceFlags` [in]

Flags controlling the creation of instances.

The parameter value may be either 0 or one of the following flags.

#### WBEM_FLAG_UPDATE_ONLY

Permits only updates.

#### WBEM_FLAG_CREATE_ONLY

Permits only new instances.

### `pInfo` [in, out]

Pointer to a [WBEM_COMPILE_STATUS_INFO](https://learn.microsoft.com/windows/win32/api/wbemcli/ns-wbemcli-wbem_compile_status_info) that describes an error.

If the parameter value is not **NULL**, an error has occurred, and the structure is filled with error information.

## Return value

This method returns **WBEM_S_NO_ERROR** if successful. If the method is unsuccessful, it returns **WBEM_S_FALSE**.

## See also

[IMofCompiler](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-imofcompiler)

[WBEM_CHANGE_FLAG_TYPE](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_change_flag_type)

[WBEM_COMPILER_OPTIONS](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_compiler_options)

[mofcomp](https://learn.microsoft.com/windows/desktop/WmiSdk/mofcomp)