# GetContextPropertyValue function

## Description

Returns a specified property value from the recognizer context.

## Parameters

### `hrc`

The handle to the recognizer context.

### `pGuid`

The property to retrieve. Specify a predefined property globally unique identifier (GUID) or application-defined GUID. For a list of predefined properties, see the recognition [Property GUIDs](https://learn.microsoft.com/windows/desktop/tablet/property-guids).

### `pcbSize`

On input, the size, in bytes, the *pProperty*  buffer can be. On output, the size, in bytes, the *pProperty* buffer is.

### `pProperty`

The user allocated buffer to contain the property value. To determine the size of the buffer, set *pProperty* to **NULL**; use the size to allocate *pProperty*.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | One of the parameters is an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |
| **TPC_E_UNINITIALIZED_PROPERTY** | The property has not been set by the context. This may occur if the property is set only in certain circumstances, or if the property is to be set only after an event that has not yet occurred. |
| **TPC_E_INVALID_PROPERTY** | The recognizer does not support the property. |
| **TPC_E_INSUFFICIENT_BUFFER** | The *pProperty* buffer is too small. |

## Remarks

This function is optional.

You can use the **GetContextPropertyValue** function to get information that the recognizer is returning to the caller. This enables a customized recognizer to have modes and settings, and to return data that is unique to that recognizer.

In the Microsoft recognizers, calling the **GetContextPropertyValue** function with the *pcbSize* parameter set to a value larger than required does not result in an incorrect return value. Instead, the code automatically changes the size to the required value for the current GUID.

## See also

[GetContextPropertyList Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getcontextpropertylist)

[SetContextPropertyValue Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setcontextpropertyvalue)