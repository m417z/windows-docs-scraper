# IMSVidVideoRenderer2::get_Allocator

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Allocator** method retrieves the allocator-presenter from the VMR as an **IUnknown** pointer.

This method is provided for Automation clients. C++ applications can also use the [get__Allocator](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer2-get__allocator) method, which returns an [IVMRSurfaceAllocator](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrsurfaceallocator) pointer.

## Parameters

### `AllocPresent` [out]

Receives a pointer to the allocator-presenter's **IUnknown** interface.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |

## Remarks

The caller must release the returned **IUnknown** interface.

## See also

[IMSVidVideoRenderer2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidvideorenderer2)