# IBackgroundCopyFile::GetProgress

## Description

Retrieves information on the progress of the file transfer.

## Parameters

### `pVal` [out]

Structure whose members indicate the progress of the file transfer. For details on the type of progress information available, see the
[BG_FILE_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_file_progress) structure.

## Return value

This method returns **S_OK** on success or one of the standard COM **HRESULT** values on error.

## See also

[BG_FILE_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_file_progress)

[IBackgroundCopyFile](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyfile)

[IBackgroundCopyJob::GetProgress](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getprogress)