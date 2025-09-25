# STREAMBUFFER_ATTR_DATATYPE enumeration

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies only to Windows XP Service Pack 1 or later.

The **STREAMBUFFER_ATTR_DATATYPE** enumeration defines the data type for an attribute.

## Constants

### `STREAMBUFFER_TYPE_DWORD:0`

The attribute is a 32-bit **DWORD** value.

### `STREAMBUFFER_TYPE_STRING:1`

The attribute is a null-terminated wide-character string.

### `STREAMBUFFER_TYPE_BINARY:2`

The attribute is an array of bytes.

### `STREAMBUFFER_TYPE_BOOL:3`

The attribute is a 32-bit Boolean value.

### `STREAMBUFFER_TYPE_QWORD:4`

The attribute is a 64-bit **QWORD** value.

### `STREAMBUFFER_TYPE_WORD:5`

The attribute is a 16-bit **WORD** value.

### `STREAMBUFFER_TYPE_GUID:6`

The attribute is a 128-bit **GUID** value.

## See also

[IStreamBufferRecordingAttribute Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferrecordingattribute)

[STREAMBUFFER_ATTRIBUTE Structure](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/ns-sbe-streambuffer_attribute)

[Stream Buffer Engine Enumeration Types](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-engine-types)