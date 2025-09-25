## Description

The **IO_DEVICE_HINT_ECP_CONTEXT** structure contains the extra create parameters (ECP) context that the I/O manager uses to pass back information to the filter manager about a reparse when the reparse target goes to a new device.

## Members

### `TargetDevice`

The reparse target device.

### `RemainingName`

String containing the remaining portion of the pathname string.

## Remarks

The system-defined GUID_ECP_IO_DEVICE_HINT value is used with this ECP context structure when calling ECP-related support routines such as [**FltAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter) and [**FsRtlRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveextracreateparameter).

See [Introduction to extra create parameters](https://learn.microsoft.com/windows-hardware/drivers/ifs/introduction-to-extra-create-parameters) for more information.