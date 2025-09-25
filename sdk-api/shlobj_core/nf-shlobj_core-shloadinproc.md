# SHLoadInProc function

## Description

Creates an instance of the specified object class from within the context of the Shell's process.

**Windows Vista** and later: This function has been disabled and returns E_NOTIMPL.

## Parameters

### `rclsid` [in]

Type: **REFCLSID**

The CLSID of the object class to be created.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. In Windows Vista and later versions, always returns E_NOTIMPL.

## Remarks

**Note** This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It is not available in later versions of Windows, including Windows Vista.

This function creates the requested object instance by calling the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) function and immediately releasing the returned object. The associated DLL is unloaded according to standard Component Object Model (COM) rules when it returns S_OK from its [DllCanUnloadNow](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-dllcanunloadnow) function.