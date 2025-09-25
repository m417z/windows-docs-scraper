# STREAMBUFFER_ATTRIBUTE structure

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies only to Windows XP Service Pack 1 or later.

The **STREAMBUFFER_ATTRIBUTE** structure describes an attribute on a stream buffer file.

## Members

### `pszName`

Pointer to a null-terminated wide-character string that contains the name of the attribute.

### `StreamBufferAttributeType`

Member of the [STREAMBUFFER_ATTR_DATATYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/ne-sbe-streambuffer_attr_datatype) enumeration. The value indicates the data type that you should use to interpret the attribute data, which is contained in the **pbAttribute** member.

### `pbAttribute`

Pointer to a buffer that contains the attribute data.

### `cbLength`

The size of the buffer given in **pbAttribute**, in bytes.

## See also

[IEnumStreamBufferRecordingAttrib::Next](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-ienumstreambufferrecordingattrib-next)

[Stream Buffer Engine Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-engine-structures)