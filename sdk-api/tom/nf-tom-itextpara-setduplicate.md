# ITextPara::SetDuplicate

## Description

Sets the formatting for an existing paragraph by copying a given format.

## Parameters

### `pPara` [in]

Type: **[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)***

The [ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara) range that contains the new paragraph formatting.

## Return value

Type: **HRESULT**

If **ITextPara::SetDuplicate** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

The tomUndefined values have no effect, that is, they will not change the target values.

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)