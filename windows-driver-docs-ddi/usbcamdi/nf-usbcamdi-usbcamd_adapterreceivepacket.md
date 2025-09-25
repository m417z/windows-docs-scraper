# USBCAMD_AdapterReceivePacket function

## Description

The **USBCAMD_AdapterReceivePacket** function allows USBCAMD to process an adapter-based stream request block (SRB).

## Parameters

### `Srb` [in]

Pointer to the SRB passed to the camera minidriver's [AdapterReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-padapter_receive_packet_routine) callback function.

### `DeviceData` [in]

Pointer to the [USBCAMD_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data) structure that contains entry points to the camera minidriver's callback functions.

### `DeviceObject` [in]

Pointer to the device's physical device object (PDO).

### `NeedsCompletion` [in]

Specifies if USBCAMD is to process and complete the SRB request. Specify **TRUE** if USBCAMD is to complete the SRB request Specify **FALSE** to make USBCAMD ignore the SRB request and return the device context pointer.

## Return value

**USBCAMD_AdapterReceivePacket** returns a pointer to the device-specific context for this instance of the camera.

## Remarks

Typically, this function is called by the camera minidriver from its [AdapterReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-padapter_receive_packet_routine) routine.

This function can also be used by the minidriver to retrieve the device context by setting the *NeedsCompletion* parameter to **FALSE**. In this case, the *DeviceData* and *DeviceObject* parameters are ignored.

## See also

[AdapterReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-padapter_receive_packet_routine)

[USBCAMD_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data)