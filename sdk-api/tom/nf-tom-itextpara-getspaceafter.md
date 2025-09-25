# ITextPara::GetSpaceAfter

## Description

Retrieves the amount of vertical space below a paragraph.

## Parameters

### `pValue`

Type: **float***

The space-after value, in floating-point points.

## Return value

Type: **HRESULT**

If **ITextPara::GetSpaceAfter** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## See also

**Conceptual**

[GetSpaceBefore](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getspacebefore)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetSpaceAfter](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setspaceafter)

[SetSpaceBefore](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setspacebefore)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)