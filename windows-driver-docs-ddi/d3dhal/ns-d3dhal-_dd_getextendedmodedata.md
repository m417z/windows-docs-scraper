# _DD_GETEXTENDEDMODEDATA structure

## Description

 DirectX 9.0 and later versions only.

DD_GETEXTENDEDMODEDATA is the data structure pointed to by the **lpvData** field of [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) for DD_GETDRIVERINFO2DATA queries with the type D3DGDI2_TYPE_GETEXTENDEDMODE.

## Members

### `gdi2`

Specifies a [DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data) structure that contains the **GetDriverInfo2** data.

### `dwModeIndex`

Specifies the index of the display mode to return.

### `mode`

Receives a D3DDISPLAYMODE structure that specifies the actual display mode.

## Remarks

The runtime identifies the display mode to be returned with an integer index whose value varies between zero and one less than the number of supported display modes that were reported earlier by the driver in a DD_GETDRIVERINFO2DATA query with the type D3DGDI2_TYPE_GETEXTENDEDMODECOUNT. How these indices are mapped to actual display modes is left to the driver. However, each index must map uniquely to one supported display mode. The order in which the display modes are reported is not significant.

When processing this **GetDriverInfo2** request the driver should read the value in the **dwModeIndex** member and map that value to one of the supported display modes (probably by using the value in **dwModeIndex** as an index into an array of D3DDISPLAYMODE structures). The driver should then copy that display mode into the **mode** member. The runtime guarantees that it only passes an index to the driver that is in the range zero to one less than the number of display modes reported by the driver. The range of the index should be validated in the debug driver build.

For more information about D3DDISPLAYMODE, see the DirectX SDK documentation.

## See also

[DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data)

[DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata)

[DD_GETEXTENDEDMODECOUNTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getextendedmodecountdata)