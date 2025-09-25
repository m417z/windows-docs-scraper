# SLDATATYPE enumeration

## Description

Specifies the data type of the buffer returned by the [SLGetWindowsInformation](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slgetwindowsinformation) function.

## Constants

### `SL_DATA_NONE:REG_NONE`

The buffer has no data type.

### `SL_DATA_SZ:REG_SZ`

The buffer contains a null-terminated Unicode string.

### `SL_DATA_DWORD:REG_DWORD`

The buffer contains a **DWORD** value.

### `SL_DATA_BINARY:REG_BINARY`

The buffer contains a binary value.

### `SL_DATA_MULTI_SZ`

The buffer contains multiple null-terminated Unicode strings.

### `SL_DATA_SUM:100`

The buffer contains a sum.