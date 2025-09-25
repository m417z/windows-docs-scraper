# ITextRange::GetStoryType

## Description

Get the type of the range's story.

## Parameters

### `pValue`

Type: **long***

The type of the range's story. The *pValue* value can be one of the following values.

| Story type | Value | Story type | Value |
| --- | --- | --- | --- |
| **tomUnknownStory** | 0 | **tomEvenPagesHeaderStory** | 6 |
| **tomMainTextStory** | 1 | **tomPrimaryHeaderStory** | 7 |
| **tomFootnotesStory** | 2 | **tomEvenPagesFooterStory** | 8 |
| **tomEndnotesStory** | 3 | **tomPrimaryFooterStory** | 9 |
| **tomCommentsStory** | 4 | **tomFirstPageHeaderStory** | 10 |
| **tomTextFrameStory** | 5 | **tomFirstPageFooterStory** | 11 |

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If *pValue* is null, the method fails and it returns E_INVALIDARG.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)