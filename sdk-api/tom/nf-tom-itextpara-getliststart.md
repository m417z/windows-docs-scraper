# ITextPara::GetListStart

## Description

Retrieves the starting value or code of a list numbering sequence.

## Parameters

### `pValue`

Type: **long***

The starting value or code of a list numbering sequence. For the possible values, see the [ITextPara::GetListType](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlisttype) method.

## Return value

Type: **HRESULT**

If **ITextPara::GetListStart** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

For a discussion on which sequence to use, see the [ITextPara::GetListType](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlisttype) method.

## See also

**Conceptual**

[GetListType](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlisttype)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetListStart](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setliststart)

[SetListType](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setlisttype)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)