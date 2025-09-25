# _FILE_MODE_INFORMATION structure

## Description

The **FILE_MODE_INFORMATION** structure is used to query or set the access mode of a file.

## Members

### `Mode`

Specifies the mode in which the file will be accessed following a create-file or open-file operation. This parameter is either zero or the bitwise OR of one or more of the following file option flags:

#### FILE_WRITE_THROUGH

Any system services, file system drivers (FSDs), and drivers that write data to the file must actually transfer the data into the file before any requested write operation is considered complete.

#### FILE_SEQUENTIAL_ONLY

All accesses to the file will be sequential.

#### FILE_NO_INTERMEDIATE_BUFFERING

The file cannot be cached or buffered in a driver's internal buffers.

#### FILE_SYNCHRONOUS_IO_ALERT

All operations on the file are performed synchronously. Any wait on behalf of the caller is subject to premature termination from alerts. This flag also causes the I/O system to maintain the file position context.

#### FILE_SYNCHRONOUS_IO_NONALERT

All operations on the file are performed synchronously. Wait requests in the system that must synchronize I/O queuing and completion are not subject to alerts. This flag also causes the I/O system to maintain the file position context.

#### FILE_DELETE_ON_CLOSE

Delete the file when the last handle to the file is closed.

These flags are defined in the Wdm.h header file. For more information, see the Remarks section.

## Remarks

This structure contains a set of flags that specify the mode in which the file can be accessed. These flags are a subset of the options that can be specified in the *CreateOptions* parameter of the [IoCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatefile) routine.

This structure is used by the [ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) routine.

## See also

[IoCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatefile)

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)