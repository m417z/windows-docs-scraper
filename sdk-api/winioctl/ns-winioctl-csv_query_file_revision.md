# CSV_QUERY_FILE_REVISION structure

## Description

Contains information about whether files in a stream have been modified.

## Members

### `FileId`

The identifier of an NTFS file.

### `FileRevision`

File revision tracking elements.

* **FileRevision**[0] increases every time the CSV MDS stack is rebuilt and CSVFLT
  loses its state.
* **FileRevision**[1] increases every time the CSV MDS stack purges the cached
  revision number for the file.
* **FileRevision**[2] increases every time the CSV MDS observes that file sizes
  might have changed or the file might have been written to. The element is also incremented whenever one of the
  nodes performs the first direct input/output operation on a stream that is associated with this file after
  opening this stream.

If any of the numbers are 0, the function caller should assume that the file was modified.

## Remarks

This structure is used if the [FSCTL_CSV_CONTROL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_csv_control)
control code is called with a [CSV_CONTROL_OP](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-csv_control_op) enumeration
value of **CsvControlQueryFileRevision**, or if the control code is used with an
[CSV_CONTROL_PARAM](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-csv_control_param) structure containing that
enumeration value.

Revision tracking is per file, not per stream, so the output changes whenever the stream changes.

## See also

[CSV_CONTROL_OP](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-csv_control_op)

[CSV_CONTROL_PARAM](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-csv_control_param)

[FSCTL_CSV_CONTROL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_csv_control)

[File Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/file-management-structures)