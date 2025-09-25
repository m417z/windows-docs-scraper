# DDVIDEOPORTBANDWIDTH structure

## Description

The DDVIDEOPORTBANDWIDTH structure describes the bandwidth characteristics of an overlay when used with a particular [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object/pixel format configuration.

## Members

### `dwSize`

Specifies the size in bytes of this DDVIDEOPORTBANDWIDTH structure.

### `dwCaps`

Specifies the dependencies of the bandwidth. The driver's [DdVideoPortGetBandwidth](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getbandwidth) function sets this member to one of the following values:

| Flag | Meaning |
| --- | --- |
| DDVPBCAPS_DESTINATION | The device's capabilities are described in terms of the destination overlay's minimum stretch factor. The bandwidth information set by the driver in the **dwOverlay**, **dwColorkey**, **dwYInterpolate**, and **dwYInterpAndColorkey** members refers to the destination overlay size. |
| DDVPBCAPS_SOURCE | The device's capabilities are described in terms of the required source overlay's rectangle size (in pixels). The bandwidth information set by the driver in the **dwOverlay**, **dwColorkey**, **dwYInterpolate**, and **dwYInterpAndColorkey** members refers to the source overlay size. |

### `dwOverlay`

Specifies the stretch factor or overlay source size at which the device can support an overlay, multiplied by 1000. The driver sets this value based on its device's type and capabilities, and on the dimensions specified in the **dwWidth** and **dwHeight** members of the [DD_GETVPORTBANDWIDTHDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportbandwidthdata) structure passed to [DdVideoPortGetBandwidth](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getbandwidth). For example, a stretch factor of 2 is specified as 2000, and an overlay source size of 750 indicates that the specified source overlay be shrunk to 75 percent of its original size. The driver must return a valid number in this member.

### `dwColorkey`

Specifies the stretch factor or overlay source size at which an overlay with color keying is supported, multiplied by 1000. The driver sets this value based on its device's type and capabilities, and on the dimensions specified in the **dwWidth** and **dwHeight** members of the DD_GETVPORTBANDWIDTHDATA structure passed to [DdVideoPortGetBandwidth](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getbandwidth). For example, a stretch factor of 2 is specified as 2000.

### `dwYInterpolate`

Specifies the stretch factor or overlay source size at which an overlay with y-axis interpolation is supported, multiplied by 1000. The driver sets this value based on its device's type and capabilities, and on the dimensions specified in the **dwWidth** and **dwHeight** members of the [DD_GETVPORTBANDWIDTHDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportbandwidthdata) structure passed to [DdVideoPortGetBandwidth](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getbandwidth). For example, a stretch factor of 2 is specified as 2000.

### `dwYInterpAndColorkey`

Specifies the stretch factor or overlay source size at which an overlay with y-axis interpolation and color keying is supported, multiplied by 1000. The driver sets this value based on its device's type and capabilities, and on the dimensions specified in the **dwWidth** and **dwHeight** members of the DD_GETVPORTBANDWIDTHDATA structure passed to [DdVideoPortGetBandwidth](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getbandwidth). For example, a stretch factor of 2 is specified as 2000.

### `dwReserved1`

Reserved for system use and should be ignored by the driver.

### `dwReserved2`

Reserved for system use and should be ignored by the driver.

## See also

[DD_GETVPORTBANDWIDTHDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportbandwidthdata)

[DdVideoPortGetBandwidth](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getbandwidth)