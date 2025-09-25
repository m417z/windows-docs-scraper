# GetResultPropertyList function

## Description

Retrieves a list of properties the recognizer can return for a result range.

## Parameters

### `hrec`

Handle to the recognizer.

### `pPropertyCount`

On input, the number of GUIDs the *pPropertyGuid* buffer can hold. On output, the number of GUIDs the *pPropertyGuid* buffer contains.

### `pPropertyGuid`

Array of properties the recognizer can return. The order of the array is arbitrary. For a list of predefined properties, see the recognition [Property GUIDs](https://learn.microsoft.com/windows/desktop/tablet/property-guids). To determine the required size of the buffer, set *pPropertyGuid* to **NULL**; use the number of GUIDs to allocate the buffer.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | One of the parameters is an invalid pointer. |
| **TPC_E_INSUFFICIENT_BUFFER** | The *pPropertyGuid* buffer is too small. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |