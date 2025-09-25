# ITfRangeBackup::Restore

## Description

Restores a specified range object into the TSF context.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit session. This is the value passed to [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that receives the backup information. If this parameter is **NULL**, the backup information is restored into a copy of the range originally backed up by **ITfContext::CreateRangeBackup**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_DISCONNECTED** | The context is not on a document stack. |
| **TF_E_NOLOCK** | The edit cookie specified by *ec* is invalid. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *pRange* is invalid. |

## See also

[ITfContext::CreateRangeBackup](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-createrangebackup)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfRangeBackup](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrangebackup)

[Ranges: Clones and Backups](https://learn.microsoft.com/windows/desktop/TSF/ranges)