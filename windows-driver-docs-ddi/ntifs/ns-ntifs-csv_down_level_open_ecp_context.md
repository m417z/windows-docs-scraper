## Description

The **CSV_DOWN_LEVEL_OPEN_ECP_CONTEXT** structure contains the extra create parameter (ECP) context sent by the Cluster Share Volumes (CSV) file system with information about the type of file create.

## Members

### `Version`

The version of the ECP context (this structure). Set to CSV_DOWN_LEVEL_OPEN_ECP_CONTEXT_V1.

### `IsResume`

Set to TRUE when the create is part of CSVFS re-establishing its state after being paused; set to FALSE otherwise.

### `FileType`

A [**CSV_DOWN_LEVEL_FILE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-csv_down_level_file_type) value that identifies the type of down-level CSVFS file object that is being opened (or reopened).

### `SourceNodeId`

Cluster ID of the node that originated this create.

### `DestinationNodeId`

Cluster ID of the node that is the target for this create.

## Remarks

The system-defined GUID_ECP_CSV_DOWN_LEVEL_OPEN value is used with this ECP context structure when calling ECP-related support routines such as [**FltAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter) and [**FsRtlRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveextracreateparameter).

See [Introduction to extra create parameters](https://learn.microsoft.com/windows-hardware/drivers/ifs/introduction-to-extra-create-parameters) for more information.