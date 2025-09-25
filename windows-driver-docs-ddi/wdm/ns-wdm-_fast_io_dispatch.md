# _FAST_IO_DISPATCH structure

## Description

Contains a set of callback routines that a file system driver or file system filter driver (legacy) provides for fast I/O processing.

## Members

### `SizeOfFastIoDispatch`

Set to **sizeof**(FAST_IO_DISPATCH).

### `FastIoCheckIfPossible`

A pointer to a callback routine that checks if fast I/O is possible for a either a read or a write operation.

### `FastIoRead`

A pointer to a callback routine that does a fast cached read, bypassing the IRP read path. It is used to perform a copy read
for a cached file object.

### `FastIoWrite`

A pointer to a callback routine that does a fast cached write, bypassing the IRP write path. It is used to perform a copy write
for a cached file object.

### `FastIoQueryBasicInfo`

A pointer to a callback routine for fast query of basic file information.

### `FastIoQueryStandardInfo`

A pointer to a callback routine for fast query of standard file information.

### `FastIoLock`

A pointer to a callback routine for doing a fast lock on a file object.

### `FastIoUnlockSingle`

A pointer to a callback routine for doing a fast release of a single lock on a file object.

### `FastIoUnlockAll`

A pointer to a callback routine for doing a fast release of a all locks held on a file object.

### `FastIoUnlockAllByKey`

A pointer to a callback routine for doing a fast release of a all locks grouped by a key.

### `FastIoDeviceControl`

A pointer to a callback routine for fast device control processing.

### `AcquireFileForNtCreateSection`

A pointer to a callback routine used by the memory manager to acquire a file exclusively.

### `ReleaseFileForNtCreateSection`

A pointer to a callback routine used by the memory manager to release a previously acquired file.

### `FastIoDetachDevice`

A pointer to a callback routine that is invoked to detach the current device object from a device object that
is being deleted.

### `FastIoQueryNetworkOpenInfo`

A pointer to a callback routine for fast query of network file information.

### `AcquireForModWrite`

A pointer to a callback routine that decides which file system resource the modified page
writer should acquire and acquires it if possible.

### `MdlRead`

A pointer to a callback routine that does a fast cached MDL read, bypassing the IRP read path. It is used to perform a copy read
for a cached file object.

### `MdlReadComplete`

A pointer to a callback routine that performs a fast completion of an MDL read.

### `PrepareMdlWrite`

A pointer to a callback routine that does a fast cached MDL write, bypassing the IRP write path. It is used to perform a copy write
for a cached file object.

### `MdlWriteComplete`

A pointer to a callback routine that performs a fast completion of an MDL write.

### `FastIoReadCompressed`

A pointer to a callback routine that performs a fast compressed read of data from a file.

### `FastIoWriteCompressed`

A pointer to a callback routine that performs a fast compressed write of data to a file.

### `MdlReadCompleteCompressed`

A pointer to a callback routine that completes a fast MDL compressed read of data from a file.

### `MdlWriteCompleteCompressed`

A pointer to a callback routine that completes a fast MDL compressed write of data to a file.

### `FastIoQueryOpen`

A pointer to a callback routine that implements a fast open for path based queries.

### `ReleaseForModWrite`

This routine releases a file system resource previously acquired for
the modified page write.

### `AcquireForCcFlush`

A pointer to a callback routine that acquires a file system resource prior to a cache flush.

### `ReleaseForCcFlush`

A pointer to a callback routine that releases a file system resource previously acquired for a cache flush.