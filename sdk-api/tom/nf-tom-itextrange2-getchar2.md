# ITextRange2::GetChar2

## Description

Gets the character at the specified offset from the end of this range.

## Parameters

### `pChar` [out]

Type: **long***

The character value.

### `Offset` [in]

Type: **long**

The offset from the end of the range. An offset of 0 gets the character at the end of the range.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method differs from [ITextRange::GetChar](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getchar) in the following ways:

* It returns the UTF-32 character for the surrogate pair instead of the pair's lead code.
* It gets the character code, or codes, at the specified offset from the end of the range instead of the character at the start of the range.

If the character is the lead code for a surrogate pair, the corresponding UTF-32 character is returned.

If *Offset* specifies a character before the start of the story or at the end of the story, this method returns the character code 0.

| If the Offset value is | This character is returned |
| --- | --- |
| 0 | The character at the end of the range. |
| Negative and accesses the middle of a surrogate pair | The corresponding UTF-32 character. |
| Positive and accesses the middle of a surrogate pair | The UTF-32 character following that pair. |

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)