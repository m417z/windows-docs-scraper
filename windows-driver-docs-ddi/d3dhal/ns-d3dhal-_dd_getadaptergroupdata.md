# _DD_GETADAPTERGROUPDATA structure

## Description

 DirectX 9.0 and later versions only.

DD_GETADAPTERGROUPDATA is the data structure pointed to by the **lpvData** field of [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) for DD_GETDRIVERINFO2DATA queries with the type D3DGDI2_TYPE_GETADAPTERGROUP.

## Members

### `gdi2`

Specifies a [DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data) structure that contains the **GetDriverInfo2** data for the query.

### `ulUniqueAdapterGroupId`

Receives the identifier of the group of adapters that comprise the driver's multiple-head video card. The driver must provide a unique identifier for the master and all subordinate adapters within this group.

### `dwReserved1`

Specifies a reserved field. Driver should not read or write. Set to zero.

### `dwReserved2`

Specifies a reserved field. Driver should not read or write. Set to zero.

## Remarks

The runtime uses DD_GETADAPTERGROUPDATA in a query for the identity of the driver's group of adapters. This group shares video hardware like video memory and the 3D accelerator. The runtime mainly uses this query for dual-view video adapters. An application can request that surface resources (like textures and vertex buffers) be shared across adapters in a group and the runtime complies with that request.

The identifier in **ulUniqueAdapterGroupId** must be unique across drivers, including drivers from other hardware vendors. Therefore, it is recommended to report this identifier as a unique kernel-mode address that cannot be common with other multiple-head video cards. Note that the driver must report this identifier as nonzero.

## See also

[DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data)

[DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata)