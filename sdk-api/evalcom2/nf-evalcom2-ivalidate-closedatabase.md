# IValidate::CloseDatabase

## Description

The **CloseDatabase** method closes the currently open Windows Installer package or merge module. Windows Installer packages or merge modules can be opened by using the [OpenDatabase](https://learn.microsoft.com/windows/desktop/api/evalcom2/nf-evalcom2-ivalidate-opendatabase) method.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

This method can also return one or more of the errors returned by the [MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle) function. The error is converted to **HRESULTS** using the **HRESULT_FROM_WIN32** function.

## See also

[IValidate](https://learn.microsoft.com/windows/desktop/api/evalcom2/nn-evalcom2-ivalidate)

[Using Evalcom2](https://learn.microsoft.com/windows/desktop/Msi/using-evalcom2)

[Validation Callback Functions](https://learn.microsoft.com/windows/desktop/Msi/validation-callback-functions)