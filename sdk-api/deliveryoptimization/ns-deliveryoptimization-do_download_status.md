## Description

The **DO_DOWNLOAD_STATUS** structure is used to obtain the status of a specific download. It is obtained by calling the **IDODownload::GetStatus** function.

## Members

### `BytesTotal`

The total number of bytes to download.

### `BytesTransferred`

The number of bytes that have already been downloaded.

### `State`

The current download state as defined by the **DODownloadState** enumeration.

### `Error`

The error information (if it exists) that is associated with the current download.

### `ExtendedError`

The extended error information (if it exists) that is associated with the current download.

## Remarks

## See also