# IFileSystemImage::put_SessionStartBlock

## Description

Sets the starting block address for the recording session.

## Parameters

### `newVal` [in]

Block number of the new recording session.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

If the previous session is imported, the session start block cannot be changed manually.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_SessionStartBlock](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_sessionstartblock)