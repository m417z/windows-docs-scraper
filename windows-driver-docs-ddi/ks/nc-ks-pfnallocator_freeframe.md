# PFNALLOCATOR_FREEFRAME callback function

## Description

The *KStrFreeFrame* routine describes a vendor-supplied frame deallocation function.

## Parameters

### `FileObject` [in]

Pointer to a [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure for which this frame has been allocated.

### `Frame` [in]

A pointer to a buffer containing the frame to release.

## Remarks

This type is used in the **FreeFrame** member of the [KSSTREAMALLOCATOR_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstreamallocator_functiontable) structure.

You can pass an instance of this structure as part of a [KSPROPERTY_STREAMALLOCATOR_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-streamallocator-functiontable) property request.

## See also

[KSPROPERTY_STREAMALLOCATOR_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-streamallocator-functiontable)

[KSSTREAMALLOCATOR_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstreamallocator_functiontable)