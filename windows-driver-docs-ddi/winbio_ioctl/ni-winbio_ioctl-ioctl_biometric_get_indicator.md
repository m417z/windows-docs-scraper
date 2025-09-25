# IOCTL_BIOMETRIC_GET_INDICATOR IOCTL

## Description

The IOCTL_BIOMETRIC_GET_INDICATOR IOCTL directs the driver to retrieve the status of the indicator light. This IOCTL is optional.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The AssociatedIrp.SystemBuffer member points to a buffer that contains a [WINBIO_GET_INDICATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_get_indicator) structure.

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

If the vendor-supplied driver passes back the entire payload, it should fill in the WinBioHresult member of WINBIO_GET_INDICATOR with the status of the biometric operation.

Possible values include: