# ITextPara::GetDuplicate

## Description

Creates a duplicate of the specified paragraph format object. The duplicate property is the default property of an [ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara) object.

## Parameters

### `ppPara`

Type: **[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)****

The duplicate [ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara) object.

## Return value

Type: **HRESULT**

If **ITextPara::GetDuplicate** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_OUTOFMEMORY** | Memory could not be allocated for the new object. |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetDuplicate](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setduplicate)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)