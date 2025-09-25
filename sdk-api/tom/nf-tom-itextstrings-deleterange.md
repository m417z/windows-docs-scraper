# ITextStrings::DeleteRange

## Description

Deletes the contents of a given range.

## Parameters

### `pRange` [in]

Type: **[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)***

The range to delete.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **S_FALSE** | Range is not degenerate. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

If the text selected by the range is not completely contained by the string, the method fails.

## See also

[ITextStrings](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstrings)