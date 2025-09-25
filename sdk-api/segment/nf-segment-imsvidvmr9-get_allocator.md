# IMSVidVMR9::get_Allocator

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **get_Allocator** method retrieves the application's custom allocator-presenter.

## Parameters

### `AllocPresent` [out]

Receives a pointer to the **IUnknown** interface of the allocator-presenter. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | The application did not set a custom allocator-presenter. |

## Remarks

To set a custom allocator-presenter, call [IMSVidVMR9::SetAllocator](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvmr9-setallocator).

## See also

[IMSVidVMR9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvmr9)