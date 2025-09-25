# CSV_CONTROL_PARAM structure

## Description

Represents a type of CSV control operation.

## Members

### `Operation`

The type of CSV control operation to undertake.

### `Unused`

Unused.

## Remarks

This structure is used with the [FSCTL_CSV_CONTROL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_csv_control)
control code to indicate what kind of CSV control operation is being undertaken. It is an alternative to calling
that control code by just passing a [CSV_CONTROL_OP](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-csv_control_op)
enumeration value, as the structure encapsulates an enumeration value of that type.

## See also

[CSV_CONTROL_OP](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-csv_control_op)

[FSCTL_CSV_CONTROL](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_csv_control)

[File Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/file-management-structures)