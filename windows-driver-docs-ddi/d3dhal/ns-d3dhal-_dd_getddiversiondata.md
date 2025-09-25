# _DD_GETDDIVERSIONDATA structure

## Description

 DirectX 9.0 and later versions only.

DD_GETDDIVERSIONDATA is the data structure pointed to by the **lpvData** field of [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) for DD_GETDRIVERINFO2DATA queries with the type D3DGDI2_TYPE_GETDDIVERSION.

## Members

### `gdi2`

Specifies a [DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data) structure that contains the **GetDriverInfo2** data for the query.

### `dwDXVersion`

Specifies the version of the DirectX runtime that makes the request. For example, the DirectX 9.0 runtime specifies 9.

### `dwDDIVersion`

Receives the version of the DDI that the driver supports.

## Remarks

During the development phase of a version of DirectX, whenever a significant change is made to the Driver Development Kit (DDK) headers, the version number of the DDI is updated. Thereafter, a display driver must report this updated DDI version in order to be run as the most-recent-version DirectX driver. If the driver does not report this updated DDI version, the runtime determines that the driver is the prior version of DirectX and handles the driver accordingly.

For example, suppose that a hardware vendor builds his display driver with a pre-released version of the DirectX 9.0 DDK and then attempts to ship his driver as a DirectX 9.0 version. If the DDI version number is updated in the final version of DirectX 9.0, the DirectX 9.0 runtime subsequently treats this driver as a DirectX 8.0 version driver instead.

## See also

[DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data)

[DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata)