# DXGK_ALLOCATIONLIST structure

## Description

The **DXGK_ALLOCATIONLIST** structure describes an allocation specification that is used in direct memory access (DMA) buffering.

## Syntax

``` C
typedef struct _DXGK_ALLOCATIONLIST
{
    HANDLE              hDeviceSpecificAllocation;
    struct
    {
        UINT            WriteOperation  : 1;    // 0x00000001
        UINT            SegmentId       : 5;    // 0x0000002E
        UINT            Reserved        : 26;   // 0xFFFFFFC0
    };
#if (DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM2_0)
    union
    {
        PHYSICAL_ADDRESS        PhysicalAddress;
        D3DGPU_VIRTUAL_ADDRESS  VirtualAddress;
    };
#else // (DXGKDDI_INTERFACE_VERSION < DXGKDDI_INTERFACE_VERSION_WDDM2_0)
    PHYSICAL_ADDRESS    PhysicalAddress;
#endif // (DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM2_0)
} DXGK_ALLOCATIONLIST;
```

## Members

### `hDeviceSpecificAllocation` [in/out]

An open handle to the allocation that is being referenced (that is, the handle that the driver returned in the **hDeviceSpecificAllocation** member of the [**DXGK_OPENALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_openallocationinfo) structure for the allocation in a call to the driver's [**DxgkDdiOpenAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_openallocationinfo) function).

### `WriteOperation` [in/out]

Identifies whether the allocation can be written to. Setting this member to 1 indicates that the allocation can be written to anywhere in the DMA buffer. Setting this member is equivalent to setting the first bit of a 32-bit value (0x00000001).

### `SegmentId` [in/out]

Specifies the identifier of a segment that the allocation was last paged in at. Setting this member to 0 indicates that no pre-patching information is available. Setting this member is equivalent to setting the second through sixth bit of a 32-bit value (0x0000002E).

### `Reserved` [in]

Reserved. This member should be set to 0. Setting this member is equivalent to setting the remaining 26 bits (0xFFFFFFC0) of a 32-bit value to zeros.

### `PhysicalAddress` [in/out]

A **PHYSICAL_ADDRESS** data type (which is defined as **LARGE_INTEGER**) that indicates the physical address, within the segment that **SegmentId** specifies, where the allocation was last paged-in at. This member is set to zero if no pre-patching information is available.

Supported starting with Windows 10.

### `VirtualAddress` [in/out]

A **D3DGPU_VIRTUAL_ADDRESS** data type (which is defined as a **ULONGLONG**) that indicates the virtual address.

Supported starting with Windows 10.

## Remarks

In the display miniport driver's [**DxgkDdiRender**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) function, the driver generates a list of **DXGK_ALLOCATIONLIST** structures for allocation specifications that will be used in a direct memory access (DMA) buffer. The video memory manager uses the list to split and patch DMA buffers appropriately.

## See also

[**DXGKARG_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation)

[**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[**DXGK_OPENALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_openallocationinfo)

[**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[**DxgkDdiOpenAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_openallocationinfo)

[**DxgkDdiRender**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render)