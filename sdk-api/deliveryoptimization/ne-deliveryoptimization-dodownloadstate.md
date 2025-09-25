## Description

The **DODownloadState** enumeration specifies the ID of the current download state, which is part of the **DO_DOWNLOAD_STATUS** structure.

## Constants

### `DODownloadState_Created`

Download object is created but hasn't been started yet.

### `DODownloadState_Transferring`

Download is in progress.

### `DODownloadState_Transferred`

Download is transferred and can start again by downloading another portion of the file.

### `DODownloadState_Finalized`

Download is finalized and cannot be started again.

### `DODownloadState_Aborted`

Download was aborted.

### `DODownloadState_Paused`

Download has been paused on demand or due to transient error.

## Remarks

## See also