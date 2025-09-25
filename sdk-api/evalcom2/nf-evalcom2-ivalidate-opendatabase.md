# IValidate::OpenDatabase

## Description

The **OpenDatabase** method opens a Windows Installer installation package or merge module for validation.

## Parameters

### `szDatabase` [in]

The fully qualified path to the installation package or merge module to be opened. The *szDatabase* parameter cannot be **NULL**.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The value of *szDatabase* is invalid. |

This method can also return one or more of the errors returned by the [MsiOpenDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiopendatabasea) function. The error is converted to **HRESULTS** using the **HRESULT_FROM_WIN32** function.

## Remarks

The **OpenDatabase** method can also accept a handle to an opened database. The handle to the opened database can be provided in the form "#nnnn" where nnnn is the database handle in string form. For example, for an opened database handle 123, the method can accept #123 for the value of *szDatabase* instead of the path to the package.

## See also

[IValidate](https://learn.microsoft.com/windows/desktop/api/evalcom2/nn-evalcom2-ivalidate)

[Using Evalcom2](https://learn.microsoft.com/windows/desktop/Msi/using-evalcom2)

[Validation Callback Functions](https://learn.microsoft.com/windows/desktop/Msi/validation-callback-functions)