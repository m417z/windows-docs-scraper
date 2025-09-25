## Description

Specifies the allocator usage of components that implement the [IMFSampleAllocatorControl](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfsampleallocatorcontrol) interface.

## Constants

### `MFSampleAllocatorUsage_UsesProvidedAllocator:0`

The output stream will use the camera pipeline's sample allocator to allocate new media samples. If the output stream is producing samples in CPU memory, it is recommended that it use this mode to ensure consistent performance when used in a cross-container scenario.

### `MFSampleAllocatorUsage_UsesCustomAllocator`

The output stream will be use a custom allocator for its output samples. It will not use the sample allocator provided by the camera pipeline.

### `MFSampleAllocatorUsage_DoesNotAllocate`

The output stream will not allocate new samples for its output samples. It will not be provided a sample allocator by the camera pipeline.

## Remarks

Components should pass a value from the enumeration back from an implementation of [IMFSampleAllocatorControl::GetAllocatorUsage](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfsampleallocatorcontrol-getallocatorusage) to let the system know if they will use the system-provided allocator.

## See also