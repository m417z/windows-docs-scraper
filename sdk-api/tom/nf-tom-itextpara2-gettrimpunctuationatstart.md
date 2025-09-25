# ITextPara2::GetTrimPunctuationAtStart

## Description

Gets whether to trim the leading space of a punctuation symbol at the start of a line.

## Parameters

### `pValue` [out, retval]

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value that can be one of the following.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Trim the leading space of a punctuation symbol at the start of a line. |
| **tomFalse** | Do not trim the leading space of a punctuation symbol at the start of a line. |
| **tomUndefined** | The TrimPunctuationAtStart property is undefined. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextPara2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara2)

[ITextPara2::SetTrimPunctuationAtStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara2-settrimpunctuationatstart)