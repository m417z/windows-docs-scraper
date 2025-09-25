# IoCheckFunctionAccess function

## Description

The **IoCheckFunctionAccess** routine checks the parameters and access for a function against the current granted access to the file.

## Parameters

### `GrantedAccess`

Mask value that specifies the access currently granted to the file for the caller.

### `MajorFunction`

Major function code for the operation being performed.

### `MinorFunction`

Minor function code for the operation being performed.

### `IoControlCode`

I/O function control code for a device or file system I/O code.

### `Arg1`

Optional argument that depends on the major function. This parameter points to one of the [FILE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class) enum values if *MajorFunction* indicates a query or set file information function is being performed.

### `Arg2`

Optional second argument that depends on the major function. This parameter points to one of the [FS_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_fsinfoclass) enum values. This parameter must be supplied if *MajorFunction* indicates a query or set file information function is being performed.

## Return value

**IoCheckFunctionAccess** returns STATUS_SUCCESS if the caller has access to the file; otherwise, it returns STATUS_ACCESS_DENIED.

## Remarks

The *GrantedAccess* mask cannot contain any generic mappings. That is, [IoCheckDesiredAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckdesiredaccess) must have been previously invoked to return a full mask.

## See also

[FILE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class)

[FS_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_fsinfoclass)

[IoCheckDesiredAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckdesiredaccess)

[SeAccessCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck)