# ITfReverseConversion::DoReverseConversion

## Description

[**DoReverseConversion** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For internal use only.]

Performs a reverse conversion of the specified string.

## Parameters

### `lpstr` [in]

The string to convert.

### `ppList` [out]

 The result of the conversion: a list of the key strokes required to create the string specified by *lpstr*.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The conversion result is stored in *ppList*. |
| S_FALSE | The conversion result, *ppList*, contains no entries. |
| E_FAIL | An unspecified error occurred. |

## Remarks

A reverse conversion provides the keystroke sequences required to create the specified string.

## See also

[ITfReverseConversion](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfreverseconversion)