# GetManagementAppHyperlink function

## Description

Retrieves the management app hyperlink associated with the MDM service.

## Parameters

### `cchHyperlink` [in]

Contains the maximum length that can be returned through the *pszHyperlink*
parameter.

### `pszHyperlink`

Address of a buffer that receives the **NULL**-terminated Unicode string with the
hyperlink of the management app associated with the management service.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. If the function
fails, the returned value describes the error. Possible values include those listed at
[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants).

## Remarks

The caller of this function must be running as an elevated process.

## See also

[MDM Registration Error Values](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-constants)

[MDM Registration Functions](https://learn.microsoft.com/windows/desktop/MDMReg/mdm-registration-functions)