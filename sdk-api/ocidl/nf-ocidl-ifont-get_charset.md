# IFont::get_Charset

## Description

Retrieves the character set used in the font. The character set can be any of those defined
for Windows fonts.

## Parameters

### `pCharset` [out]

A pointer to the caller-allocated variable that receives the character set
value.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The character set was retrieved successfully. |
| **E_POINTER** | The address in the *pCharset* parameter is not valid. For example, it may be **NULL**. |

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)

[IFont::put_Charset](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ifont-put_charset)