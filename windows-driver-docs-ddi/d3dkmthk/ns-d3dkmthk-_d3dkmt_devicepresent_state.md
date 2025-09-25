# _D3DKMT_DEVICEPRESENT_STATE structure

## Description

The D3DKMT_DEVICEPRESENT_STATE structure describes parameters for retrieving the present status for a device.

## Members

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology to receive present status for.

### `PresentStats` [out]

A [D3DKMT_PRESENT_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present_stats) structure that describes status of present operations that is retrieved for the device.

## See also

[D3DKMT_GETDEVICESTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getdevicestate)

[D3DKMT_PRESENT_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present_stats)