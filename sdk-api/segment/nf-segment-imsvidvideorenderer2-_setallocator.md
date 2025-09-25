# IMSVidVideoRenderer2::_SetAllocator

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **_SetAllocator** method specifies an allocator-presenter for the VMR. Applications can use this method to provide their own custom allocator-presenter objects.

## Parameters

### `AllocPresent` [in]

Pointer to the [IVMRSurfaceAllocator](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrsurfaceallocator) interface of the allocator-presenter object.

### `ID` [in]

Optionally, specifies an identifier (ID) for the allocator-presenter object. The default value of -1 indicates that the [MSVidVideoRenderer](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd695138(v=vs.85)) object will create an ID when it builds the filter graph. In that case, the MSVidVideoRenderer object uses the lower 32 bits of the allocator-presenter's **IUnknown** interface pointer as the ID. Note that the ID is for application use; the VMR does not use it.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |

## See also

[IMSVidVideoRenderer2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidvideorenderer2)