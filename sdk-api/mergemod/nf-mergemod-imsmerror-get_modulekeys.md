# IMsmError::get_ModuleKeys

## Description

The
**get_ModuleKeys** method retrieves the
[ModuleKeys](https://learn.microsoft.com/windows/desktop/Msi/error-modulekeys) property of the [Error](https://learn.microsoft.com/windows/desktop/Msi/error-object) object. This method returns a pointer to a string collection that contains the primary keys of the row in the module causing the error, one key per entry in the collection.

## Parameters

### `ErrorKeys` [out]

A pointer to a location in memory that receives a pointer to a string collection.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | ErrorKeys is null. |
| **S_OK** | The function succeeded. |

## Remarks

The client is responsible for releasing the string collection when it is no longer required.

The collection is empty if the values do not apply to the type of the error. You can determine the type of error by calling [IMsmError::get_Type](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmerror-get_type).

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)