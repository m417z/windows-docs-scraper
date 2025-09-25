# ITextPara::SetListStart

## Description

Sets the starting number or Unicode value for a numbered list.

## Parameters

### `Value` [in]

Type: **long**

New starting number or Unicode value for a numbered list.

## Return value

Type: **HRESULT**

If **ITextPara::SetListStart** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

Other characteristics of a list are specified by [ITextPara::SetListType](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setlisttype).

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetListType](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setlisttype)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)