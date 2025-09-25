# ITextRange::SetPara

## Description

Sets the paragraph attributes of this range to those of the specified [ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara) object.

## Parameters

### `pPara` [in]

Type: **[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)***

The paragraph object with the desired paragraph format.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Text is write-protected. |
| **E_INVALIDARG** | *pPara* is null. |
| **E_OUTOFMEMORY** | Out of memory. |

## See also

**Conceptual**

[GetPara](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getpara)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)