# SetContextPropertyValue function

## Description

Adds a property to the recognizer context.

If a property already exists, its value is modified.

## Parameters

### `hrc`

The handle to the recognizer context.

### `pGuid`

The property to set. Specify a predefined property globally unique identifier (GUID) or application-defined property GUID. For a list of predefined properties, see the recognition [Property GUIDs](https://learn.microsoft.com/windows/desktop/tablet/property-guids).

### `cbSize`

The size, in bytes, of the *pProperty* buffer.

### `pProperty`

The buffer that contains the property value.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |
| **E_POINTER** | *pGUID* is invalid or *cbSize* has been set to a very large, invalid value. |
| **TPC_E_INVALID_PROPERTY** | *pGUID* is invalid. |
| **E_INVALIDARG** | *cbSize* is invalid. |
| **S_FALSE** | Returned when an attempt is made to set a property value when it has already been enabled. |

## Remarks

The **SetContextPropertyValue** function is optional.

## See also

[GetContextPropertyList Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getcontextpropertylist)

[GetContextPropertyValue Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getcontextpropertyvalue)