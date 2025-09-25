# FsRtlMdlReadCompleteDev function

## Description

The **FsRtlMdlReadCompleteDev** routine completes the read operation that the [FsRtlMdlReadDev](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlmdlreaddev) routine initiated.

## Parameters

### `FileObject` [in]

A pointer to the file object.

### `MdlChain` [in]

On return, a pointer to a linked list of one or more MDLs that point to the cached file data.

### `DeviceObject` [ in, optional ]

A pointer to a device object on which the file is opened.

## Return value

None

## Remarks

The **FsRtlMdlReadCompleteDev** routine unlocks the pages in cache memory that the [FsRtlMdlReadDev](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlmdlreaddev) routine allocated.

## See also

[FsRtlMdlReadDev](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlmdlreaddev)