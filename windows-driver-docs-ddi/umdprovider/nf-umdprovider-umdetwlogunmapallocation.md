# UMDEtwLogUnmapAllocation function

## Description

Indicates that a Microsoft DirectX graphics kernel subsystem (Dxgkrnl.sys) memory allocation, or a portion of the allocation, is no longer being used. Call this function whether or not the allocation is being destroyed.

## Parameters

### `hD3DAllocation`

A handle to the Direct3D allocation.

 For Direct3D 10 user-mode drivers, the handle will be the value of the *hResource* parameter of the [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource) function. For Direct3D 9 user-mode drivers, the handle will be the value of the *pResource* parameter that the driver returns in the [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) function.

The driver can set this value to **NULL** if it uses allocations internally.

### `hDxgAllocation`

A handle to the DirectX graphics kernel subsystem (Dxgkrnl.sys) allocation that the Direct3D allocation is mapped to.

### `Offset`

The starting address, in bytes, of the Direct3D allocation within the Dxgkrnl allocation.

### `Size`

The size, in bytes, of the Direct3D allocation within the Dxgkrnl allocation.

### `Usage`

A [UMDETW_ALLOCATION_USAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/umdprovider/ns-umdprovider-_umdetw_allocation_usage) structure that indicates the reason for this mapping.

### `Semantic`

If the allocation is used internally by the user-mode driver, this is a [UMDETW_ALLOCATION_SEMANTIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/umdprovider/ne-umdprovider-_umdetw_allocation_semantic) structure that indicates what the allocation is used for.

## Remarks

When called, this function logs an event that describes which API resource the allocation is, or was, being used for. If no API resource was associated with the allocation, the function logs an event that describes the purpose that the driver indicated for this allocation.

The user-mode display driver must completely account for the video memory it allocates, so it must call this function to log an event every time the allocation changes.

The driver should pass the same parameters values to **UMDEtwLogUnmapAllocation** as it did to [UMDEtwLogMapAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/umdprovider/nf-umdprovider-umdetwlogmapallocation).

**UMDEtwLogUnmapAllocation** is defined inline in Umdprovider.h as:

```cpp
FORCEINLINE void LogMapAllocation(BOOLEAN Enter,
                    ULONGLONG hD3DAllocation,
                    ULONGLONG hDxgAllocation,
                    ULONGLONG Offset,
                    ULONGLONG Size,
                    UMDETW_ALLOCATION_USAGE Usage,
                    UMDETW_ALLOCATION_SEMANTIC Semantic)
{
    if (Enabled)
    {
        EVENT_DATA_DESCRIPTOR Descriptors[6];

        // Create a description of the event
        EventDataDescCreate(&Descriptors[0], &hD3DAllocation, 8);
        EventDataDescCreate(&Descriptors[1], &hDxgAllocation, 8);
        EventDataDescCreate(&Descriptors[2], &Offset, 8);
        EventDataDescCreate(&Descriptors[3], &Size, 8);
        EventDataDescCreate(&Descriptors[4], &Usage, 4);
        EventDataDescCreate(&Descriptors[5], &Semantic, 4);

        // Log the event
        EventWrite(
            RegHandle,
            Enter ? (InRundown ? &RundownAllocationEvent : &MapAllocationEvent) : &UnmapAllocationEvent,
            sizeof(Descriptors) / sizeof(Descriptors[0]),
            Descriptors
        );
    }
}

FORCEINLINE void UMDEtwLogUnmapAllocation(ULONGLONG hD3DAllocation,
                              ULONGLONG hDxgAllocation,
                              ULONGLONG Offset,
                              ULONGLONG Size,
                              UMDETW_ALLOCATION_USAGE Usage,
                              UMDETW_ALLOCATION_SEMANTIC Semantic)
{
    LogMapAllocation(FALSE,
                     hD3DAllocation,
                     hDxgAllocation,
                     Offset,
                     Size,
                     Usage,
                     Semantic);
}
```

## See also

[CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource)

[CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource)

[UMDETW_ALLOCATION_SEMANTIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/umdprovider/ne-umdprovider-_umdetw_allocation_semantic)

[UMDETW_ALLOCATION_USAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/umdprovider/ns-umdprovider-_umdetw_allocation_usage)

[UMDEtwLogMapAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/umdprovider/nf-umdprovider-umdetwlogmapallocation)