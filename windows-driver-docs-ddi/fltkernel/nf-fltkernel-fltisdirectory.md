# FltIsDirectory function

## Description

A minifilter driver calls the **FltIsDirectory** routine to determine whether a given file object represents a directory.

## Parameters

### `FileObject` [in]

Pointer to an already opened file object.

### `Instance` [in]

Opaque instance pointer for the instance associated with this file object.

### `IsDirectory` [out]

Pointer to a caller-supplied Boolean variable. On return, this variable receives **TRUE** if the file object represents a directory, **FALSE** otherwise.

## Return value

**FltIsDirectory** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_NOT_SUPPORTED** | This error code is returned if the file system does not support stream contexts. Note that starting with Windows Vista, [FltIsDirectory](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisdirectory) will return directory information even for file systems that do not support stream contexts. |

## Remarks

**FltIsDirectory** retrieves the desired information from the filter manager's internal stream context manager. The filter manager caches this information for future queries on this stream.

**Note** This routine can only be called on an opened file object.

## See also

[FsRtlSupportsPerStreamContexts](https://learn.microsoft.com/previous-versions/ff547285(v=vs.85))