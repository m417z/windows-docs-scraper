# CryptCATPersistStore function

## Description

[The **CryptCATPersistStore** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATPersistStore** function saves the information in the specified catalog store to an unsigned catalog file.

## Parameters

### `hCatalog` [in]

A handle to the catalog obtained from [CryptCATHandleFromStore](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcathandlefromstore) or [CryptCATOpen](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatopen) function. Beginning with Windows 8 you must use only **CryptCATOpen** to retrieve a handle.

## Return value

The return value is **TRUE** if the function succeeds; otherwise, **FALSE**.

If this function returns **FALSE**, additional error information can be obtained by calling the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. **GetLastError** will return the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters are not valid. |
| **ERROR_NOT_SUPPORTED** | Beginning with Windows 8 and Windows Server 2012, you must retrieve a handle by calling the [CryptCATOpen](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatopen) function with the *dwPublicVersion* parameter set to 0x100 or 0x200. For more information, see Remarks. |

## Remarks

The [CRYPTCATSTORE](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatstore) structure must be initialized before you call **CryptCATPersistStore**.

Beginning with Windows 8 and Windows Server 2012, the following changes apply to this function:

* If [CryptCATOpen](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatopen) was called with a *dwPublicVersion* parameter of 0x200, the catalog is written by using the v2 format.
* If [CryptCATOpen](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatopen) was called with a *dwPublicVersion* parameter of 0x100, the catalog is written by using the v1 format.
* If [CryptCATOpen](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatopen) was called with a *dwPublicVersion* parameter other than 0x200 or 0x100, the **CryptCATPersistStore** function returns **FALSE** and the error code is set to **ERROR_NOT_SUPPORTED**.