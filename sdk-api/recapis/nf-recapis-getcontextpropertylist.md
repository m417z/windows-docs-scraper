# GetContextPropertyList function

## Description

Retrieves a list of properties the recognizer supports.

## Parameters

### `hrc`

The handle to the recognizer context.

### `pcProperties`

On input, the size, in bytes, the *pPropertyGUIDS* buffer can be. On output, the size, in bytes, the *pPropertyGUIDS* buffer is.

### `pPropertyGUIDS`

The user-allocated buffer to contain a list of properties the recognizer supports. To determine the size of the buffer, set *pPropertyGUIDS* to **NULL**; use the size (*pcProperties*) to allocate *pPropertyGUIDS*. For a list of predefined properties, see the recognition [Property GUIDs](https://learn.microsoft.com/windows/desktop/tablet/property-guids).

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | One of the parameters is an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |
| **TPC_E_INSUFFICIENT_BUFFER** | The *ppPropertyGUIDS* buffer is too small. |

## Remarks

This function is optional.

When Microsoft recognition engines are called with the *pcProperties* parameter set to a value larger than the required value, it does not result in an error. Instead, the engine automatically changes the size to the required value for the recognizer.

## See also

[GetContextPropertyValue Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getcontextpropertyvalue)

[SetContextPropertyValue Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setcontextpropertyvalue)