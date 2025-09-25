# ITextPara::GetLineSpacing

## Description

Retrieves the line-spacing value for the text range.

## Parameters

### `pValue`

Type: **float***

The line-spacing value. The following table shows how this value is interpreted for the different line-spacing rules.

| Line spacing rule | Meaning |
| --- | --- |
| tomLineSpaceSingle | The line-spacing value is ignored. |
| tomLineSpace1pt5 | The line-spacing value is ignored. |
| tomLineSpaceDouble | The line-spacing value is ignored. |
| tomLineSpaceAtLeast | The line-spacing value specifies the spacing, in floating-point points, from one line to the next. However, if the value is less than single spacing, the control displays single-spaced text. |
| tomLineSpaceExactly | The line-spacing value specifies the exact spacing, in floating-point points, from one line to the next (even if the value is less than single spacing). |
| tomLineSpaceMultiple | The line-spacing value specifies the line spacing, in lines. |

## Return value

Type: **HRESULT**

If **ITextPara::GetLineSpacing** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

To retrieve the line-spacing rule, call the [ITextPara::GetLineSpacingRule](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlinespacingrule) method.

## See also

**Conceptual**

[GetLineSpacingRule](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlinespacingrule)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetLineSpacing](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setlinespacing)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)