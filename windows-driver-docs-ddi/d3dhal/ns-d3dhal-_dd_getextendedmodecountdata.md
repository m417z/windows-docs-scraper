# _DD_GETEXTENDEDMODECOUNTDATA structure

## Description

 DirectX 9.0 and later versions only.

DD_GETEXTENDEDMODECOUNTDATA is the data structure pointed to by the **lpvData** field of [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) for DD_GETDRIVERINFO2DATA queries with the type D3DGDI2_TYPE_GETEXTENDEDMODECOUNT.

## Members

### `gdi2`

Specifies a [DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data) structure that contains the **GetDriverInfo2** data for the query.

### `dwModeCount`

Receives the number of supported extended display modes.

### `dwReserved`

Specifies a reserved field. Driver should not read or write.

## Remarks

To handle D3DGDI2_TYPE_GETEXTENDEDMODECOUNT, the driver must store the number of extended display modes that it supports in the **dwModeCount** member of DD_GETEXTENDEDMODECOUNTDATA. Display modes are described by D3DDISPLAYMODE structures. For more information about D3DDISPLAYMODE, see the DirectX SDK documentation.

## See also

[DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data)

[DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata)

[DD_GETEXTENDEDMODEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getextendedmodedata)