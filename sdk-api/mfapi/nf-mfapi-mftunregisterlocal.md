# MFTUnregisterLocal function

## Description

Unregisters one or more Media Foundation transforms (MFTs) from the caller's process.

## Parameters

### `pClassFactory` [in]

A pointer to the **IClassFactory** interface of a class factory object. This parameter can be **NULL**.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The MFT specified by the *pClassFactory* parameter was not registered in this process. |

## Remarks

Use this function to unregister a local MFT that was previously registered through the [MFTRegisterLocal](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregisterlocal) function.

If the *pClassFactory* parameter is **NULL**, all local MFTs in the process are unregistered. Otherwise, the function unregisters the MFT associated with the class factory specified by the *pClassFactory* parameter. In that case, the *pClassFactory* parameter should equal a pointer value that was previously passed to the [MFTRegisterLocal](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregisterlocal) function.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)