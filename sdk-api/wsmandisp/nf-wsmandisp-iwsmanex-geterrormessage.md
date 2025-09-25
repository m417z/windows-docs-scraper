# IWSManEx::GetErrorMessage

## Description

Returns a formatted string containing the text of an error number. This method performs the same operation as the **Winrm** command-line **winrm helpmsg** *error number*.

## Parameters

### `errorNumber` [in]

Error message number in decimal or hexadecimal from WinRM, WinHTTP, or other operating system components.

### `errorMessage` [out]

Error message string formatted like messages returned from the **Winrm** command.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The corresponding scripting method is [WSMan.GetErrorMessage](https://learn.microsoft.com/windows/desktop/WinRM/wsman-geterrormessage).

## See also

[IWSManEx](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanex)

[IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession)