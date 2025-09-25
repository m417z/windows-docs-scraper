# ITextPara::GetLineSpacingRule

## Description

Retrieves the line-spacing rule for the text range.

## Parameters

### `pValue`

Type: **long***

A variable that is one of the following values to indicate the line-spacing rule.

#### tomLineSpaceSingle

#### tomLineSpace1pt5

#### tomLineSpaceDouble

#### tomLineSpaceAtLeast

#### tomLineSpaceExactly

#### tomLineSpaceMultiple

#### tomLineSpacePercent

## Return value

Type: **HRESULT**

If **ITextPara::GetLineSpacingRule** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## See also

**Conceptual**

[GetLineSpacing](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlinespacing)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetLineSpacing](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setlinespacing)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)