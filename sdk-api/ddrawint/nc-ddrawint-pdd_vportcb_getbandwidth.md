## Description

The **DdVideoPortGetBandwidth** callback function reports the bandwidth limitations of the device's frame buffer memory based the specified VPE object output format.

## Parameters

### `unnamedParam1`

Points to a [DD_GETVPORTBANDWIDTHDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportbandwidthdata) structure that contains the information required for the driver to return the bandwidth data.

## Return value

**DdVideoPortGetBandwidth** returns one of the following callback codes:

## Remarks

**DdVideoPortGetBandwidth** must be implemented in DirectDraw drivers that support VPE.

**DdVideoPortGetBandwidth** informs clients of bandwidth requirements for any specified format, helping them to choose a format and better understand its limitations. The driver can supply accurate bandwidth information only after the VPE object has been created because the driver needs the information in the [DDVIDEOPORTDESC](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportdesc) structure.

**DdVideoPortGetBandwidth** is typically called twice to obtain the bandwidth parameters of the specified hardware video port. Depending on the **dwFlags** member of the DD_GETVPORTBANDWIDTHDATA structure at *lpGetVideoPortBandwidth*, the driver should do the following:

* When the flag is DDVPB_TYPE, the driver should indicate the type of device it is by setting one of the following flags in the **dwCaps** member of the [DDVIDEOPORTBANDWIDTH](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportbandwidth) structure to which the **lpBandwidth** member of DD_GETVPORTBANDWIDTHDATA points:
  + DDVPBCAPS_DESTINATION indicates that the device will describe its bandwidth capabilities in terms of the overlay stretch factor; that is, that the bandwidth information returned by the driver in the next call to **DdVideoPortGetBandwidth** will refer to the size of the destination overlay. This flag best describes hardware that refreshes from both the primary and overlay surfaces simultaneously. As the destination video is stretched, the hardware has more time to read the pixels from the overlay surface, decreasing the required memory bandwidth.
  + DDVPBCAPS_SOURCE indicates that the device will describe its bandwidth capabilities in terms of the required source overlay size; that is, that the bandwidth information returned by the next call to **DdVideoPortGetBandwidth** refers to the size of the source overlay. This flag best describes hardware that prefetches the overlay data into a line buffer or large FIFO. Such hardware does not require extra bandwidth, but does require that the source overlay data fit entirely within the buffer/FIFO size supported by the hardware.

  The driver should also set the **dwSize** member of the DDVIDEOPORTBANDWIDTH structure before returning.
* When the flag is DDVPB_VIDEOPORT, the **dwWidth** and **dwHeight** members in the DD_GETVPORTBANDWIDTHDATA structure refer to the prescale size of the video data that the hardware video port will write to the frame buffer as the source overlay. The driver should return an overlay stretch factor at which the device can display the overlay, multiplied by 1000, in each of the **dwOverlay**, **dwColorkey**, **dwYInterpolate**, and **dwYInterpAndColorkey** members of the DDVIDEOPORTBANDWIDTH structure. For example, a value of 2000 indicates that the device has the bandwidth to stretch the overlay to two times the source's specified size when displaying it. A value of 1000 indicates that no stretching need be done for the specified data size. A value of 500 indicates that the device has sufficient bandwidth to shrink the overlay destination in half. The driver must set a valid value in **dwOverlay**, but can return -1 in any of the other three members that it does not support.

  The DDVPB_VIDEOPORT flag assumes that the device is best described by the DDVPBCAPS_DESTINATION flag. If this is not the case, the driver should fail the call.
* When the DDVPB_OVERLAY flag is set, the **dwWidth** and **dwHeight** members in the DD_GETVPORTBANDWIDTHDATA structure refer to the source overlay size. The driver should return a percentage of this overlay's size, multiplied by 1000, at which it can support displaying the overlay in each of the **dwOverlay**, **dwColorkey**, **dwYInterpolate**, and **dwYInterpAndColorkey** members of the DDVIDEOPORTBANDWIDTH structure. For example, a value of 750 indicates that the device requires the specified source overlay to be shrunk to 75% of its original size in order for the device to successfully display it. A value of 1000 indicates that no shrinking is required. Drivers for this type of device do not typically return a value greater than 1000. The driver must set a valid value in **dwOverlay**, but can return 0 in any of the other three members if it does not support color keying and/or Y-axis interpolation.

  The DDVPB_OVERLAY flag assumes that the device is best described using the DDVPBCAPS_SOURCE flag. If this is not the case, the driver should fail the call.

## See also

[DDVIDEOPORTBANDWIDTH](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportbandwidth)

[DDVIDEOPORTDESC](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportdesc)

[DD_GETVPORTBANDWIDTHDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportbandwidthdata)

[DdVideoPortCreate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_createvideoport)