# PADAPTER_RECEIVE_PACKET_ROUTINE callback function

## Description

A camera minidriver's *AdapterReceivePacket* callback function processes adapter-based stream request blocks (SRBs) passed to it by the stream class driver.

## Parameters

### `Srb` [in]

Specifies the SRB to be processed by the camera minidriver.

## Remarks

A camera's minidriver provides USBCAMD with the address of its *AdapterReceivePacket* function that processes SRBs in its call to the **USBCAMD_DriverEntry** service.

## See also

[USBCAMD_DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nf-usbcamdi-usbcamd_driverentry)