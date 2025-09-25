# ITextRange2::SetDropCap

## Description

Not implemented.

Sets the drop-cap parameters for the paragraph that contains the current range.

## Parameters

### `cLine` [in]

Type: **long**

The count of lines for drop cap. Zero means no drop cap.

### `Position` [in]

Type: **long**

The position of drop cap. It can be one of the following.

tomDropMargin

tomDropNone

tomDropNormal

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |

## Remarks

The current range can be degenerate, or you can select up to the complete drop-cap paragraph. If the range contains more than one paragraph, this method returns **E_FAIL**.

## See also

[ITextRange2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange2)

[ITextRange2::GetDropCap](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange2-getdropcap)