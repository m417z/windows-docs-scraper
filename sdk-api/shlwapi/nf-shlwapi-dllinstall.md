# DllInstall function

## Description

Handles installation and setup for a DLL.

## Parameters

### `bInstall`

Type: **BOOL**

**TRUE** if the DLL is being installed; **FALSE** if it is being uninstalled.

### `pszCmdLine` [in, optional]

Type: **PCWSTR**

A string passed in by **regsvr32** that indicates which setup procedure to use. This value can be **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function may be implemented and exported by name by a DLL for use during application installation or setup. It is invoked by **regsvr32** to allow the DLL to perform tasks such as adding information to the registry.

**DllInstall** is used only for application installation and setup. It should not be called by an application. It is similar in purpose to [DllRegisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllregisterserver) or [DllUnregisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllunregisterserver). Unlike these functions, **DllInstall** takes an input string which can be used to specify a variety of different actions. This allows a DLL to be installed in more than one way, based on any criteria that is appropriate.

To use **DllInstall** with **regsvr32**, add a "/i" flag followed by a colon (:) and a string. The string will be passed to **DllInstall** as the *pszCmdLine* parameter. If you omit the colon and string, *pszCmdLine* will be set to **NULL**. The following example would be used to install a DLL.

**regsvr32 /i:"Install_1" dllname.dll**

**DllInstall** is invoked with *bInstall* set to **TRUE** and *pszCmdLine* set to "Install_1". To uninstall a DLL, use the following:

**regsvr32 /u /i:"Install_1" dllname.dll**

With both of the above examples, [DllRegisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllregisterserver) or [DllUnregisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllunregisterserver) will also be called. To call **DllInstall** only, add a "/n" flag.

**regsvr32 /n /i:"Install_1" dllname.dll**