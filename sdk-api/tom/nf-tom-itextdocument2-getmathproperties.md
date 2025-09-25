# ITextDocument2::GetMathProperties

## Description

Gets the math properties for the document.

## Parameters

### `pOptions` [out]

Type: **long***

A combination of the following math properties.

| Property | Meaning |
| --- | --- |
| **[tomMathDispAlignMask](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Display-mode alignment mask. |
| **[tomMathDispAlignCenter](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Center (default) alignment. |
| **[tomMathDispAlignLeft](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Left alignment. |
| **[tomMathDispAlignRight](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Right alignment. |
| **[tomMathDispIntUnderOver](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Display-mode integral limits location. |
| **[tomMathDispFracTeX](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Display-mode nested fraction script size. |
| **[tomMathDispNaryGrow](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Math-paragraph n-ary grow. |
| **[tomMathDocEmptyArgMask](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Empty arguments display mask. |
| **[tomMathDocEmptyArgAuto](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Automatically use a dotted square to denote empty arguments, if necessary. |
| **[tomMathDocEmptyArgAlways](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Always use a dotted square to denote empty arguments.. |
| **[tomMathDocEmptyArgNever](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Don't denote empty arguments. |
| **[tomMathDocSbSpOpUnchanged](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Display the underscore (_) and caret (^) as themselves. |
| **[tomMathDocDiffMask](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Style mask for the **tomMathDocDiffUpright**, **tomMathDocDiffItalic**, **tomMathDocDiffOpenItalic**  options. |
| **[tomMathDocDiffItalic](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Use italic (default) for math differentials. |
| **[tomMathDocDiffUpright](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Use an upright font for math differentials. |
| **[tomMathDocDiffOpenItalic](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Use open italic (default) for math differentials. |
| **[tomMathDispNarySubSup](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Math-paragraph non-integral n-ary limits location. |
| **[tomMathDispDef](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Math-paragraph spacing defaults. |
| **[tomMathEnableRtl](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Enable right-to-left (RTL) math zones in RTL paragraphs. |
| **[tomMathBrkBinMask](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Equation line break mask. |
| **[tomMathBrkBinBefore](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Break before binary/relational operator. |
| **[tomMathBrkBinAfter](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Break after binary/relational operator. |
| **[tomMathBrkBinDup](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Duplicate binary/relational before/after. |
| **[tomMathBrkBinSubMask](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Duplicate mask for minus operator. |
| **[tomMathBrkBinSubMM](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | - - (minus on both lines). |
| **[tomMathBrkBinSubPM](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | + - |
| **[tomMathBrkBinSubMP](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | - + |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)

 [ITextDocument2::GetProperty](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-getproperty)

 [ITextDocument2::SetMathProperties](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument2-setmathproperties)