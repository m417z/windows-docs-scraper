# IAmsiStream::Read

## Description

Requests a buffer-full of content to be read.

## Parameters

### `position` [in]

The zero-based index into the content at which the read is to begin.

### `size` [in]

The number of bytes to read from the content.

### `buffer` [out]

Buffer into which the content is to be read.

### `readSize` [out]

The number of bytes read into *buffer*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more argument is invalid. |
| **E_NOT_VALID_STATE** | The object is not initialized. |

## See also

[IAmsiStream](https://learn.microsoft.com/windows/desktop/api/amsi/nn-amsi-iamsistream)