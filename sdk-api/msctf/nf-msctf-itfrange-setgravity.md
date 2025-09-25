# ITfRange::SetGravity

## Description

Sets the gravity of the anchors in the object.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit context obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `gStart` [in]

Contains one of the [TfGravity](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfgravity) values that specifies the gravity of the start anchor.

### `gEnd` [in]

Contains one of the **TfGravity** values that specifies the gravity of the end anchor.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **TF_E_NOLOCK** | The cookie in *ec* is invalid. |

## See also

[Anchor Gravity](https://learn.microsoft.com/windows/desktop/TSF/ranges)

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfRange::GetGravity](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-getgravity)

[TfGravity](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfgravity)