# ITextPara2::SetDuplicate2

## Description

Sets the properties of this object by copying the properties of another text paragraph object.

## Parameters

### `pPara` [in]

Type: **[ITextPara2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara2)***

The text paragraph object to copy from.

## Return value

Type: **HRESULT**

If **ITextPara2::SetDuplicate2** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## Remarks

**tomUndefined** values have no effect.

## See also

[ITextPara2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara2)

[ITextPara2::GetDuplicate2](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara2-getduplicate2)