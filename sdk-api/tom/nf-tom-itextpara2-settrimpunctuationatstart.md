# ITextPara2::SetTrimPunctuationAtStart

## Description

Sets whether to trim the leading space of a punctuation symbol at the start of a line.

## Parameters

### `Value` [in]

Type: **long**

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) that indicates whether to trim the leading space of a punctuation symbol. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **tomTrue** | Trim the leading space of a punctuation symbol at the start of a line. |
| **tomFalse** | Do not trim the leading space of a punctuation symbol at the start of a line. |
| **tomToggle** | Toggle the TrimPunctuationAtStart property. |
| **tomUndefined** | The TrimPunctuationAtStart property is undefined. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextPara2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara2)

[ITextPara2::GetTrimPunctuationAtStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara2-gettrimpunctuationatstart)