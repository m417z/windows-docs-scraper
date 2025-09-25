# IOCTL_BIOMETRIC_UPDATE_FIRMWARE IOCTL

## Description

The IOCTL_BIOMETRIC_UPDATE_FIRMWARE IOCTL tells the driver to update the firmware for the device with the given firmware image. This IOCTL is optional.

## Parameters

### Major code

### Input buffer

[WINBIO_UPDATE_FIRMWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_update_firmware)

### Input buffer length

Length of a [WINBIO_UPDATE_FIRMWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_update_firmware) structure.

### Output buffer

The AssociatedIrp.SystemBuffer member points to a buffer that contains a [WINBIO_BLANK_PAYLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_blank_payload) structure.

### Output buffer length

The smallest valid output buffer size is the size of DWORD. If the driver receives an DWORD-sized output buffer, the driver should return the buffer size necessary for the requested operation.

### Input/output buffer

### Input/output buffer length

### Status block

Indicates whether the DeviceIoControl call to the driver completed and the OUT payload is valid.

The **Status** member is set to one of the values in the following table.

|Status value|Description|
|--- |--- |
|S_OK, STATUS_SUCCESS|The operation completed successfully. If the size of data returned is DWORD, the payload contains the size of the buffer necessary for the call. Otherwise, the payload contains the full output buffer.|
|E_INVALIDARG|The parameters were not specified correctly.|
|E_UNKNOWN|Any other failure that prevents the payload from being filled in.|
|E_UNEXPECTED|Any other failure that prevents the payload from being filled in.|
|E_FAIL|Any other failure that prevents the payload from being filled in.|

## Remarks

The firmware image is specific to each vendor and may contain both firmware data and any extra data that the driver needs to validate the image.

If the device has a different firmware update mechanism, the driver can return E_NOTIMPL for this IOCTL.

If the vendor-supplied driver passes back the entire payload, it should fill in the WinBioHresult member of WINBIO_BLANK_PAYLOAD with the status of the Biometric operation.

Possible values include: