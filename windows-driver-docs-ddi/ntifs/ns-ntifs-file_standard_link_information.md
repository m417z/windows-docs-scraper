## Description

**FILE_STANDARD_LINK_INFORMATION** is used to query file link information.

## Members

### `NumberOfAccessibleLinks`

Number of non-deleted links to this file.

### `TotalNumberOfLinks`

Total number of links to this file, including links marked for delete.

### `DeletePending`

Boolean value. This field must be set to TRUE to indicate that a file deletion has been requested; otherwise, set to FALSE.

### `Directory`

Set to 1 to indicate that the file is a directory; otherwise, set to FALSE.

## Remarks

## See also

[**NtQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)