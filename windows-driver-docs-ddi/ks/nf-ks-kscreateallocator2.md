# KsCreateAllocator2 function

## Description

Creates a handle to an allocator for the given sink connection handle. This function does not complete the IRP or set the status in the IRP.

Supported starting in Windows 8.

## Parameters

### `ConnectionHandle` [in]

Specifies the handle to the sink connection on which to create the allocator.

### `AllocatorFraming` [in]

A pointer to a [KSALLOCATOR_FRAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing) structure that specifies framing for the allocator.

### `AllocatorHandle` [out]

Specifies the pointer to a handle to store the allocator handle.

## Return value

Returns **NOERROR** if successful; otherwise, returns an error code.

## Remarks

This is a new version of the [KsCreateAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreateallocator) function and uses the device broker to create the handle to the kernel streaming object. In addition, the Component Object Model (COM) [CoInitialize](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-coinitialize) function must be called before this function is called.

## See also

[CoInitialize](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-coinitialize)

[KSALLOCATOR_FRAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing)

[KsCreateAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreateallocator)