# IMSVidVMR9::SetAllocator

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **SetAllocator** method sets a custom allocator-presenter for the VMR-9.

## Parameters

### `AllocPresent` [in]

Pointer to the **IUnknown** interface of the allocator-presenter. This object must expose the [IVMRSurfaceAllocator9](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrsurfaceallocator9) interface. To use the VMR-9 filter's default allocator-presenter, set this parameter to **NULL**.

### `ID` [in]

Application-defined identifier for the allocator-presenter.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMSVidVMR9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvmr9)