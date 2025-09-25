# ENUM_PAGE_FILE_INFORMATION structure

## Description

Contains information about a pagefile.

## Members

### `cb`

The size of this structure, in bytes.

### `Reserved`

This member is reserved.

### `TotalSize`

The total size of the pagefile, in pages.

### `TotalInUse`

The current pagefile usage, in pages.

### `PeakUsage`

The peak pagefile usage, in pages.

## See also

[EnumPageFilesProc](https://learn.microsoft.com/windows/desktop/api/psapi/nc-psapi-penum_page_file_callbacka)