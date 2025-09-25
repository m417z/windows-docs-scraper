# ITfReverseConversionList::GetString

## Description

[**GetString** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For internal use only.]

Retrieves the keystroke sequence at the specified index.

## Parameters

### `uIndex` [in]

 The index of the keystroke sequence to retrieve.

### `pbstr` [out]

 The keystroke sequence at the specified index.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The keystroke sequence is stored in *pbstr*. |
| E_INVALIDARG | The specified index is out of range. |
| E_FAIL | An unspecified error occurred. |

## See also

[ITfReverseConversionList](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfreverseconversionlist)