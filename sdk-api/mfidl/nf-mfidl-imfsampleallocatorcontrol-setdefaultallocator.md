## Description

Sets the default sample allocator to use for the specified output stream.

## Parameters

### `dwOutputStreamID`

The ID of the output stream that the *pAllocator* parameter applies to.

### `pAllocator`

Receives a pointer to a sample allocator to use for the specified output stream. The
allocator supports one of the MF allocator interfaces, such as [IMFVideoCaptureSampleAllocator](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfvideocapturesampleallocator) or [IMFVideoSampleAllocatorEx](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfvideosampleallocatorex).

## Return value

The method returns an **HRESULT**.

## Remarks

The system calls this method to provide components with a sample allocator that allows the component to allocate samples using memory that is accessible from within a container.

Components that use the provided allocator should return [MFSampleAllocatorUsage_UsesProvidedAllocator](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mfsampleallocatorusage) from calls to [IMFSampleAllocatorControl::GetAllocatorUsage](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfsampleallocatorcontrol-setdefaultallocator).

## See also