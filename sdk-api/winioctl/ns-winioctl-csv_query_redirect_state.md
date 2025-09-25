# CSV_QUERY_REDIRECT_STATE structure

## Description

Contains information about whether files in a stream have been redirected.

## Members

### `MdsNodeId`

The identifier of an MDS node.

### `DsNodeId`

The identifier of a DS node.

### `FileRedirected`

**TRUE** if the file has been redirected; otherwise,
**FALSE**.

## Remarks

This structure is used if the [FSCTL_CSV_CONTROL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_csv_control)
control code is called with a [CSV_CONTROL_OP](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-csv_control_op) enumeration
value of **CsvControlQueryRedirectState**, or if the control code is used with an
[CSV_CONTROL_PARAM](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-csv_control_param) structure containing that enumeration
value.

## See also

[CSV_CONTROL_OP](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-csv_control_op)

[CSV_CONTROL_PARAM](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-csv_control_param)

[FSCTL_CSV_CONTROL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_csv_control)

[File Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/file-management-structures)