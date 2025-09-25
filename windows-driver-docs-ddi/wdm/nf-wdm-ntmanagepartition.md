## Description

The **NtManagePartition** function gets and sets information for a partition.

## Parameters

### `TargetHandle` [in]

Supplies a handle to a partition.

### `SourceHandle` [in, optional]

Optionally supplies a handle to a source partition. This handle is only used for particular information classes.

### `PartitionInformationClass` [in]

Supplies the partition object information class which is to be managed.

### `PartitionInformation` [in, out]

Supplies a pointer to a buffer which contains the specified information. The format and content of the buffer depends on the partition class.

### `PartitionInformationLength` [in]

Supplies the length, in bytes, of the partition information buffer.

## Return value

Returns an appropriate NTSTATUS value.

## Remarks

## See also