# ITfRange::GetGravity

## Description

Obtains the gravity of the anchors in the object.

## Parameters

### `pgStart` [out]

Pointer to a [TfGravity](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfgravity) value that receives the gravity of the start anchor.

### `pgEnd` [out]

Pointer to a **TfGravity** value that receives the gravity of the end anchor.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## See also

[Anchor Gravity](https://learn.microsoft.com/windows/desktop/TSF/ranges)

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfRange::SetGravity](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-setgravity)

[TfGravity](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfgravity)