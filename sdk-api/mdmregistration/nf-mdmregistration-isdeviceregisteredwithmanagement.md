# IsDeviceRegisteredWithManagement function

## Description

Checks whether the device is registered with an MDM service. If the device is registered,
it also returns the user principal name (UPN) of the registered user.

## Parameters

### `pfIsDeviceRegisteredWithManagement` [out]

Address of a **BOOL** indicates whether the device is registered.

### `cchUPN` [in, optional]

Contains the maximum length that can be returned through the *pszUPN*
parameter.

### `pszUPN` [out, optional]

Optional address of a buffer that receives the **NULL**-terminated Unicode string
containing the UPN of the user registered with the management service. If *pszUPN* is
**NULL** then the **BOOL** pointed to by the
*pfIsDeviceRegisteredWithManagement* parameter is updated to indicate whether the device
is registered and the function returns **ERROR_SUCCESS**.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS** and the
**BOOL** pointed to by the
*pfIsDeviceRegisteredWithManagement* parameter contains **TRUE**
or **FALSE**. If **TRUE**, the Unicode string pointed to by the
*pszUPN* parameter contains the UPN of the registered user. If the function fails, the
returned value describes the error. Possible values include those listed at
[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants).

If the buffer size indicated by the *cchUPN* parameter is too small then the call will fail with
**STRSAFE_E_INSUFFICIENT_BUFFER** but the **BOOL** pointed to by
the *pfIsDeviceRegisteredWithManagement* parameter will be updated to indicate whether
the device is registered.

## See also

[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants)

[MDM Registration Functions](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-functions)