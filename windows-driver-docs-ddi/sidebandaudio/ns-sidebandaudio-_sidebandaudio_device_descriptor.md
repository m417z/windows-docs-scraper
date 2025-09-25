# SIDEBANDAUDIO_DEVICE_DESCRIPTOR structure

## Description

The **SIDEBANDAUDIO_DEVICE_DESCRIPTOR** structure describes the number of endpoints on the device.

## Members

### `NumberOfEndpoints`

Number of Audio endpoints on the devices that can be sidebanded. This number excludes the feedback endpoints.

## Remarks

A device can contain multiple audio endpoints that can be used in Sideband mode. The number of endpoints can be used to iterate through all the endpoints contained in the device using a 0 based index (0 to n-1).

The driver should call [IOCTL_SBAUD_GET_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_endpoint_descriptor) iteratively to get details about each of the endpoints.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)

[IOCTL_SBAUD_GET_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_endpoint_descriptor)