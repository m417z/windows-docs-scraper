# PrjWriteFileData function

## Description

Provides the data requested in an invocation of the [PRJ_GET_FILE_DATA_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_file_data_cb) callback.

## Parameters

### `namespaceVirtualizationContext` [in]

Opaque handle for the virtualization instance.

If the provider is servicing a [PRJ_GET_FILE_DATA_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_file_data_cb) callback, this must be the value from the VirtualizationInstanceHandle member of the callbackData passed to the provider in the callback.

### `dataStreamId` [in]

Identifier for the data stream to write to.

If the provider is servicing a [PRJ_GET_FILE_DATA_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_file_data_cb) callback, this must be the value from the DataStreamId member of the callbackData passed to the provider in the callback.

### `buffer` [in]

Pointer to a buffer containing the data to write. The buffer must be at least as large as the value of the length parameter in bytes. The provider should use [PrjAllocateAlignedBuffer](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjallocatealignedbuffer) to ensure that the buffer meets the storage device's alignment requirements.

### `byteOffset` [in]

Byte offset from the beginning of the file at which to write the data.

### `length` [in]

The number of bytes to write to the file.

## Return value

HRESULT_FROM_WIN32(ERROR_OFFSET_ALIGNMENT_VIOLATION) indicates that the user's handle was opened for unbuffered I/O and byteOffset is not aligned to the sector size of the storage device.

## Remarks

The provider uses this routine to provide the data requested in an invocation of its [PRJ_GET_FILE_DATA_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_file_data_cb) callback.

The provider’s [PRJ_GET_FILE_DATA_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_file_data_cb) callback is invoked when the system needs to ensure that a file contains data. When the provider calls [PrjWriteFileData](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjwritefiledata) to supply the requested data the system uses the user’s FILE_OBJECT to write that data to the file. However the system cannot control whether that FILE_OBJECT was opened for buffered or unbuffered I/O. If the FILE_OBJECT was opened for unbuffered I/O, reads and writes to the file must adhere to certain alignment requirements. The provider can meet those alignment requirements by doing two things:

* Use [PrjAllocateAlignedBuffer](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjallocatealignedbuffer) to allocate the buffer to pass to buffer.
* Ensure that byteOffset and length are integer multiples of the storage device’s alignment requirement (length does not have to meet this requirement if byteOffset + length is equal to the end of the file). The provider can use [PrjGetVirtualizationInstanceInfo](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjgetvirtualizationinstanceinfo) to retrieve the storage device’s alignment requirement.

The system leaves it up to the provider to calculate proper alignment because when processing a [PRJ_GET_FILE_DATA_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_file_data_cb) callback the provider may opt to return the requested data across multiple [PrjWriteFileData](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjwritefiledata) calls, each returning part of the total requested data.

Note that if the provider is going to write the entire file in a single call to [PrjWriteFileData](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjwritefiledata), i.e. from byteOffset = 0 to length = size of the file, the provider does not have to do any alignment calculations. However it must still use [PrjAllocateAlignedBuffer](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjallocatealignedbuffer) to ensure that buffer meets the storage device's alignment requirements. See the [File Buffering](https://learn.microsoft.com/windows/desktop/FileIO/file-buffering) topic for more information on buffered vs unbuffered I/O.