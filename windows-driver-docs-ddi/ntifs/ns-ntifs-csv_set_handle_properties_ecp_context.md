## Description

The **CSV_SET_HANDLE_PROPERTIES_ECP_CONTEXT** structure contains the extra create parameter (ECP) context that can be sent to the Cluster Shared Volumes (CSV) file system to set properties for how it should handle IO arriving on this open.

## Members

### `Size`

Size of this structure, in bytes.

### `PauseTimeoutInSeconds`

The number of seconds that CSVFS is allowed to hold IO issued on this file object in a pending state in case of CSV volume pause. Once time expires CSV will complete all IO issued on this file object with status STATUS_CSV_IO_PAUSE_TIMEOUT. This member can be one of the following values.

| Value | Meaning |
| ---------- | ------- |
| 0xFFFFFFFF | Indicates that there is no timeout, and default behavior is requested. |
| 0 | CSV will not pause IO, and will complete IO immediately. |
| Any other value | CSV will round up all other values to a multiple of 10 seconds and use this value as the timeout. The maximum supported timeout value is 30 minutes. If the provided value is greater than 30 minutes, CSV will silently set the value to the maximum value. |

### `Flags`

The set property flags. This member can be a bitwise OR of the following flags.

| Flag | Meaning |
| ---- | ------- |
| CSV_SET_HANDLE_PROPERTIES_ECP_CONTEXT_FLAGS_VALID_ONLY_IF_CSV_COORDINATOR | Tells CSVFS that this file open should be valid only on the coordinating node. If the open comes to CSVFS and the node is not a coordinating node, the open will fail. If the file is opened and the coordinating node is moved, the file open will be invalidated. This flag is used only when the file is opened directly on CSVFS, and is ignored when the file is opened over SMB. |

The lower 16 bits of **Flags** are for flags that would cause the create to fail with STATUS_INVALID_PARAMETER if CSV does not recognize them. The upper 16 bits are for flags that would be silently ignored if CSVFS does not know how to handle them.

## Remarks

The system-defined GUID_ECP_CSV_SET_HANDLE_PROPERTIES value is used with this ECP context structure when calling ECP-related support routines such as [**FltAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter) and [**FsRtlRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveextracreateparameter).

See [Introduction to extra create parameters](https://learn.microsoft.com/windows-hardware/drivers/ifs/introduction-to-extra-create-parameters) for more information.