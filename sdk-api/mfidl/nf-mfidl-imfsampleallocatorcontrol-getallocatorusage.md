## Description

Retrieves the sample allocator usage for the specified output stream.

## Parameters

### `dwOutputStreamID`

The ID of the output stream whose sample allocator usage is requested.

### `pdwInputStreamID`

If the allocator usage is [MFSampleAllocatorUsage_DoesNotAllocate](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mfsampleallocatorusage), then this output parameter is set to the ID of the input stream that the output samples are coming from. For all other allocator usage values, this parameter is ignored.

### `peUsage`

A member of the [MFSampleAllocatorUsage](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mfsampleallocatorusage) enumeration specifying the sample allocator usage of the specified output stream.

## Return value

The method returns an **HRESULT**.

## Remarks

## See also