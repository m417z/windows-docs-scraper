# IMSVidVMR9::get_Allocator_ID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **get_Allocator_ID** method retrieves the identifier of the application's custom allocator-presenter.

## Parameters

### `ID` [out]

Receives the identifier. If the application did not set an allocator-presenter, the value is 1.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To set a custom allocator-presenter, call [IMSVidVMR9::SetAllocator](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvmr9-setallocator).

## See also

[IMSVidVMR9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvmr9)