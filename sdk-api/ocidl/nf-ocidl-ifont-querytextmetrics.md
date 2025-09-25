# IFont::QueryTextMetrics

## Description

Fills a caller-allocated structure with information about the font.

## Parameters

### `pTM` [out]

Pointer to the caller-allocated structure that receives the font information. The
**TEXTMETRICOLE** structure is defined as a
[TEXTMETRICW](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-textmetrica) structure.

## Return value

The method supports the standard return value **E_UNEXPECTED**, as well as the
following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The text metrics were returned successfully. |
| **E_POINTER** | The address in the *ptm* parameter is not valid. For example, it may be **NULL**. |

## Remarks

### Notes to Implementers

**E_NOTIMPL** is not a valid return value. Font objects must always provide their font
information through this call unless other errors occur.

## See also

[IFont](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ifont)