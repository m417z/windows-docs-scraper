# USBD_CalculateUsbBandwidth function

## Description

The **USBD_CalculateUsbBandwidth** routine has been deprecated in Windows XP and later operating systems. Do not use.

## Parameters

### `MaxPacketSize` [in]

Specifies the maximum packet size.

### `EndpointType` [in]

Contains a value of type [USBD_PIPE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ne-usb-_usbd_pipe_type) that specifies the pipe type.

### `LowSpeed` [in]

Indicates, when **TRUE**, that the device is a low speed device. When **FALSE**, this member indicates that the device is a hi-speed device.

## Return value

The **USBD_CalculateUsbBandwidth** routine returns zero for bulk and control endpoints and the bandwidth consumed in bits per millisecond. returns for all other endpoints.

## Remarks

The **USBD_CalculateUsbBandwidth** routine approximates the bandwidth using the following procedure. First, **USBD_CalculateUsbBandwidth** adds the largest possible packet size, specified in *MaxPacketSize*, to the overhead associated with the type of end point specified in *EndpointType*. Next, **USBD_CalculateUsbBandwidth** multiplies this sum by 8 to convert the units from *bytes* per millisecond into *bits* per millisecond. Finally, **USBD_CalculateUsbBandwidth** multiplies this quantity by 7/6 to account for filler bits. In a worst case scenario, there will be one bit of filler data stuffed into the data stream for every six bits of data. **USBD_CalculateUsbBandwidth** uses worst-case assumptions to calculate the bandwidth required by the pipe.

## See also

[USB device driver programming reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/)

[USBD_PIPE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ne-usb-_usbd_pipe_type)