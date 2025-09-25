# ITextPara::GetListType

## Description

Retrieves the kind of numbering to use with paragraphs.

## Parameters

### `pValue`

Type: **long***

A variable that is of the following values to indicate the kind of list numbering.

#### tomListNone

#### tomListBullet

#### tomListNumberAsArabic

#### tomListNumberAsLCLetter

#### tomListNumberAsUCLetter

#### tomListNumberAsLCRoman

#### tomListNumberAsUCRoman

#### tomListNumberAsSequence

#### tomListNumberedCircle

#### tomListNumberedBlackCircleWingding

#### tomListNumberedWhiteCircleWingding

#### tomListNumberedArabicWide

#### tomListNumberedChS

#### tomListNumberedChT

#### tomListNumberedJpnChs

#### tomListNumberedJpnKor

#### tomListNumberedArabic1

#### tomListNumberedArabic2

#### tomListNumberedHebrew

#### tomListNumberedThaiAlpha

#### tomListNumberedThaiNum

#### tomListNumberedHindiAlpha

#### tomListNumberedHindiAlpha1

#### tomListNumberedHindiNum

By default, numbers are followed by a right parenthesis, for example: 1). However, *pValue* can include one of the following flags to indicate a different formatting.

#### tomListMinus

#### tomListParentheses

#### tomListPeriod

#### tomListPlain

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If **ITextPara::GetListType** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

Values above 32 correspond to Unicode values for bullets.

The mobile Microsoft Office version of the rich edit control uses [tomIgnoreNumberStyle](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) to suppress setting the style.

The following Microsoft Visual Basic for Applications (VBA) example numbers the paragraphs in a range, starting with the number 2 and following the numbers with a period.

```
    range.Para.ListStart = 2
    range.Para.ListType = tomListNumberAsArabic + tomListPeriod
```

For an example of [tomListNumberAsSequence](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants), set `ListStart` to 0x2780, which gives you circled numbers. The [Unicode Standard](https://www.unicode.org/standard/standard.html) has examples of many more numbering sequences.

## See also

**Conceptual**

[GetListStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getliststart)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetListStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setliststart)

[SetListType](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setlisttype)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)