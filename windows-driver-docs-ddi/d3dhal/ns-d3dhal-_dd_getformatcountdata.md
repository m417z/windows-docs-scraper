# _DD_GETFORMATCOUNTDATA structure

## Description

 DirectX 8.0 and later versions only.

DD_GETFORMATCOUNTDATA is the data structure pointed to by the **lpvData** field of [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) for DD_GETDRIVERINFO2DATA queries with the type D3DGDI2_TYPE_GETFORMATCOUNT.

## Members

### `gdi2`

Specifies a [DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data) structure that contains the **GetDriverInfo2** data.

### `dwFormatCount`

Receives the number of supported surface formats.

### `dwReserved`

**DirectX 8.0 and 8.1 versions only.** Specifies a reserved field. Driver should not read or write.

**DirectX 9.0 and later versions only.** Specifies the version of the DirectX runtime being used by the application. This member is set to DD_RUNTIME_VERSION, which is 0x00000900 for DirectX 9.0.

## Remarks

To handle the D3DGDI2_TYPE_GETFORMATCOUNT request, the driver must store the number of DirectX 8.0 and later DDI style surface formats that it supports in the **dwFormatCount** member of DD_GETFORMATCOUNTDATA. For more information, see [The Texture Format List](https://learn.microsoft.com/windows-hardware/drivers/display/the-texture-format-list).

## See also

[DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data)

[DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata)