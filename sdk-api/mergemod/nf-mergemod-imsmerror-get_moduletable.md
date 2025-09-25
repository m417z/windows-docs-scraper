# IMsmError::get_ModuleTable

## Description

The
**get_ModuleTable** method retrieves the
[ModuleTable](https://learn.microsoft.com/windows/desktop/Msi/error-moduletable) property of the
[Error](https://learn.microsoft.com/windows/desktop/Msi/error-object) object. This method returns the name of the table in the module that caused the error.

## Parameters

### `ErrorTable` [out]

A pointer to a location in memory that is filled in with a **BSTR** value.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | Table is null. |
| **E_OUTOFMEMORY** | The system was unable to allocate memory for the string. |
| **S_OK** | The function succeeded. |

## Remarks

The client is responsible for freeing the resulting string using **SysFreeString**.

The collection is empty if the values do not apply to the type of the error. You can determine the type of error by calling [IMsmError::get_Type](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmerror-get_type).

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)