# ITextPara::GetRightIndent

## Description

Retrieves the size of the right margin indent of a paragraph.

## Parameters

### `pValue`

Type: **float***

The right indentation, in floating-point points.

## Return value

Type: **HRESULT**

If **ITextPara::GetRightIndent** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetRightIndent](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setrightindent)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)