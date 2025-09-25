# IMSVidVideoRenderer2::get__Allocator

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get__Allocator** method retrieves the allocator-presenter from the VMR.

## Parameters

### `AllocPresent` [out]

Receives an [IVMRSurfaceAllocator](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrsurfaceallocator) interface pointer.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | NULL pointer argument. |

## Remarks

The caller must release the [IVMRSurfaceAllocator](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrsurfaceallocator) interface.

## See also

[IMSVidVideoRenderer2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidvideorenderer2)