# DXGKARGCB_CREATECONTEXTALLOCATION structure

## Description

The **DXGKARGCB_CREATECONTEXTALLOCATION** structure contains the allocation attributes of a GPU context or device-specific context used in the [**DXGKCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation) callback function.

## Members

### `ContextAllocationFlags` [in]

A [**DXGK_CREATECONTEXTALLOCATIONFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createcontextallocationflags) structure that specifies the properties of the allocation.

### `hAdapter` [in]

A handle to the graphics adapter for which the context allocation is created.

### `hDevice` [in]

A handle to the display device that was originally passed by the DirectX graphics subsystem to the display miniport driver's [**DxgkDdiCreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice) function.

> [!NOTE]
>
> This member is set to NULL for a system device.

### `hContext` [in]

If **ContextAllocationFlags.SharedAcrossContexts** is set to a value of 0, this member contains the value assigned by the DirectX graphics subsystem for the context that was passed to the [**DXGKCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation) function.

If **ContextAllocationFlags.SharedAcrossContexts** is set to a value of 1, this member should be set to **NULL**.

> [!NOTE]
>
> This member is also set to NULL for a system context.

### `hDriverAllocation` [in]

A handle created by the display miniport driver that identifies the created allocation. The value of this member is subsequently passed as the **Transfer.hAllocation** member of the [**DXGKARG_BUILDPAGINGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_buildpagingbuffer) structure that is pointed to by the **pBuildPagingBuffer** parameter of the [**DxgkDdiBuildPagingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) function.

### `Size` [in]

The size, in bytes, that is required for the allocation.

### `Alignment` [in]

The required alignment, in bytes, for the allocation.

### `SupportedSegmentSet` [in]

Segment identifiers that the display miniport driver can set in the **PreferredSegment** member for read or write operations.

### `EvictionSegmentSet` [in]

Identifiers of segments that can be used for eviction.

### `PreferredSegment` [in]

A [**DXGK_SEGMENTPREFERENCE**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff562047(v=vs.85)) structure that indicates the preferred segment identifiers that the display miniport driver requests that the video memory manager use to page-in the allocation.

### `HintedBank` [in]

A [**DXGK_SEGMENTBANKPREFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentbankpreference) structure that indicates the bank ordering preferences that the display miniport driver requests that the video memory manager use to page-in the allocation.

### `Flags` [in]

A [**DXGK_ALLOCATIONINFOFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags) structure that identifies properties for an allocation in bit-field flags. These properties indicate the type of allocation to create. The display miniport driver specifies these flags for the video memory manager. See Remarks for restrictions on flag values.

### `hAllocation` [out]

A handle that has been assigned by the DirectX graphics subsystem to the allocation. This value is subsequently passed as the **hAllocation** parameter of the [**DXGKCB_DESTROYCONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroycontextallocation) function.

### `PhysicalAdapterIndex` [in]

The index of the physical adapter. This field is available starting in WDDM 2.0.

## Remarks

The display miniport driver calls [**DXGKCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation) to allocate a GPU context or device-specific context. When the driver calls this function, it passes a pointer to a **DXGKARGCB_CREATECONTEXTALLOCATION** structure through the **ContextAllocation** parameter.

## See also

[**DXGK_ALLOCATIONINFOFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags)

[**DXGK_CREATECONTEXTALLOCATIONFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createcontextallocationflags)

[**DXGK_SEGMENTBANKPREFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentbankpreference)

[**DXGK_SEGMENTPREFERENCE**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff562047(v=vs.85))

[**DXGKCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation)

[**DXGKCB_DESTROYCONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_destroycontextallocation)