# ITextStrings::SuffixTop

## Description

Suffixes a string to the top string in the collection.

## Parameters

### `bstr` [in]

Type: **BSTR**

The text to suffix to the top string.

### `pRange` [in]

Type: **[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)***

The range with the desired character formatting.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

This method is similar to [ITextStrings::Append](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextstrings-append), but appends a string instead of a range.

## See also

[ITextStrings](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstrings)