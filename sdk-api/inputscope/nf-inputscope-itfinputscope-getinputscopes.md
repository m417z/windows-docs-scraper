# ITfInputScope::GetInputScopes

## Description

Gets the input scopes that are associated with this context.

## Parameters

### `pprgInputScopes` [out]

Pointer to an array of pointers to the input scopes. The calling function must call **CoTaskMemFree()** to free the buffer.

### `pcCount` [out]

Pointer to the number of input scopes returned.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |