# IOCTL_BIOMETRIC_SET_INDICATOR IOCTL

## Description

The IOCTL_BIOMETRIC_SET_INDICATOR IOCTL directs the driver to update the status of the indicator light. The light can be turned on or off. This IOCTL is optional.This IOCTL must be implemented if the driver supports the WINBIO_CAPABILITY_INDICATOR capability.

## Parameters

### Major code

### Input buffer

[WINBIO_SET_INDICATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_set_indicator)

### Input buffer length

Length of a [WINBIO_SET_INDICATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_set_indicator) structure.

### Output buffer

The AssociatedIrp.SystemBuffer member points to a buffer that contains a WINBIO_BLANK_PAYLOAD structure.

### Output buffer length

The smallest valid output buffer size is the size of DWORD. If the driver receives a DWORD-sized output buffer, the driver should return the buffer size necessary for the requested operation.

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

If the vendor-supplied driver passes back the entire payload, it should fill in the WinBioHresult member of WINBIO_BLANK_PAYLOAD with the status of the biometric operation.

Possible values include: