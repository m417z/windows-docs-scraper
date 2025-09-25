# PFNALLOCATOR_ALLOCATEFRAME callback function

## Description

The *KStrAllocateFrame* routine describes a vendor-supplied frame allocation function.

## Parameters

### `FileObject` [in]

Pointer to a [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure for which to allocate frames.

### `Frame` [out]

A pointer to a caller-allocated buffer in which the new frame is returned.

## Return value

Returns STATUS_SUCCESS if the request is handled. Otherwise returns an appropriate error code.

## Remarks

This type is used in the **AllocateFrame** member of the [KSSTREAMALLOCATOR_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstreamallocator_functiontable) structure.

You can pass an instance of this structure as part of a [KSPROPERTY_STREAMALLOCATOR_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-streamallocator-functiontable) property request.

## See also

[KSPROPERTY_STREAMALLOCATOR_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-streamallocator-functiontable)

[KSSTREAMALLOCATOR_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstreamallocator_functiontable)