# ITextPara::SetAlignment

## Description

Sets the paragraph alignment.

## Parameters

### `Value` [in]

Type: **long**

New paragraph alignment. For a list of possible values, see the [ITextPara::GetAlignment](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getalignment) method.

## Return value

Type: **HRESULT**

If **ITextPara::SetAlignment** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## See also

**Conceptual**

[GetAlignment](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getalignment)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)