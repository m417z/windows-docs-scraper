# IMsmError::get_Path

## Description

The
**get_Path** method retrieves the
[Path](https://learn.microsoft.com/windows/desktop/Msi/error-path) property of the
[Error](https://learn.microsoft.com/windows/desktop/Msi/error-object) object.

## Parameters

### `ErrorPath` [out]

A pointer to a location in memory that is filled in with a **BSTR** value.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | Path is null. |
| **E_OUTOFMEMORY** | The system was unable to allocate memory for the string. |
| **S_OK** | The function succeeded. |

## Remarks

The client is responsible for freeing the resulting string using **SysFreeString**.

In Windows Installer versions 1.0 and 1.1
**get_Path** always returns the empty string. Future versions of the class may use this function to return the path to the file or directory that could not be created. This value is only valid for errors of type msmErrorFileCreate or msmErrorDirCreate. You can determine the type of error by calling [IMsmError::get_Type](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmerror-get_type).

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)