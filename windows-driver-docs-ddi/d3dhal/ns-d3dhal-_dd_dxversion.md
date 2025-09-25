# _DD_DXVERSION structure

## Description

 DirectX 8.0 and later versions only.

DD_DXVERSION describes the current DirectX runtime version.

## Members

### `gdi2`

Specifies a [DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data) structure that contains the **GetDriverInfo2** data.

### `dwDXVersion`

Specifies the version of DirectX. This member is set to DD_RUNTIME_VERSION, which is 0x00000700 for DirectX 7.0 and 0x00000800 for DirectX 8.0.

### `dwReserved`

Reserved. Driver should not read or write.

## Remarks

This information is provided to a new driver (one that exposes **GetDriverInfo2**) for DX7 and DX8 applications.

The runtime provides a pointer to a DD_DXVERSION structure in the **lpvData** field of the [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) data structure.

The **gdi2** member of DD_DXVERSION is used by the runtime with type D3DGDI2_TYPE_DXVERSION specified to notify the driver of the current DirectX runtime version being used by the application.

## See also

[DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data)

[DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata)