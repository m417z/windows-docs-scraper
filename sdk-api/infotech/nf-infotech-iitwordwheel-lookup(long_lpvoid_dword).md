## Description

Looks up an entry and returns contents in a buffer.

## Parameters

### `lEntry`

Entry to look up.

### `lpvKeyBuf`

Buffer in which to return entry.

### `cbKeyBuf`

Buffer size in number of bytes.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The word wheel entry was successfully returned. |
| **E_OUTOFRANGE** | Entry number is out of range. |

## See also

[IITWordWheel](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitwordwheel)