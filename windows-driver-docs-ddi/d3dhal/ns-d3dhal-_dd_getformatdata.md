# _DD_GETFORMATDATA structure

## Description

**DirectX 8.0 and later versions only.**

DD_GETFORMATDATA is the data structure pointed to by the **lpvData** field of [DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata) for DD_GETDRIVERINFO2DATA queries with the type D3DGDI2_TYPE_GETFORMAT.

## Members

### `gdi2`

Specifies a [DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data) structure that contains the **GetDriverInfo2** data.

### `dwFormatIndex`

Specifies the index of the pixel format to return.

### `format`

Receives the actual pixel format in a [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ddpixelformat) structure.

## Remarks

The runtime identifies the format to be returned with an integer index whose value varies between zero and one less than the number of supported formats reported earlier by the driver. How these indices are mapped to actual formats is left to the driver. However, each index must map uniquely to one supported format. The order in which the formats are reported is not significant.

When processing this **GetDriverInfo2** request the driver should read the **dwFormatIndex** and map that to one of the supported formats (probably by using **dwFormatIndex** as an index into an array of DDPIXELFORMAT structures) and then copy that format into the format field of the DD_GETFORMATDATA field. The runtime guarantees that it only passes an index to the driver that is in the range zero to one less than the number of surface formats reported by the driver. The range of the index should be validated in the debug driver build.

**DirectX 9.0 and later versions only.**On input, the version of the DirectX runtime that is being used by the application is specified in the **dwSize** member of the DDPIXELFORMAT structure in **format**. This **dwSize** member is set to DD_RUNTIME_VERSION, which is 0x00000900 for DirectX 9.0.

## See also

[DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ddpixelformat)

[DD_GETDRIVERINFO2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_dd_getdriverinfo2data)

[DD_GETDRIVERINFODATA](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_getdriverinfodata)