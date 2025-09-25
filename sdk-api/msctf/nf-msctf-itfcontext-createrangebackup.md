# ITfContext::CreateRangeBackup

## Description

Creates a backup of a range.

## Parameters

### `ec` [in]

Contains an edit cookie that identifies the edit session. This is the value passed to [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `pRange` [in]

Pointer to the [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object to be backed up.

### `ppBackup` [out]

Pointer to an [ITfRangeBackup](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrangebackup) interface pointer that receives the backup of *pRange*.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_NOLOCK** | The cookie in *ec* is invalid. |
| **TF_E_DISCONNECTED** | The context is not on a document stack. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This method creates a copy of the range that it can use to restore the data in [ITfRangeBackup::Restore](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrangebackup-restore).

## See also

[ITfContext interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontext), [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfeditsession-doeditsession), [ITfRange interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfrange), [ITfRangeBackup interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfrangebackup), [ITfRangeBackup::Restore](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfrangebackup-restore), [Ranges: Clones and Backups](https://learn.microsoft.com/windows/desktop/TSF/ranges)