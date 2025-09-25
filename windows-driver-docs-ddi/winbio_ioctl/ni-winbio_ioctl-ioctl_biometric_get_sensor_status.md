# IOCTL_BIOMETRIC_GET_SENSOR_STATUS IOCTL

## Description

The IOCTL_BIOMETRIC_GET_SENSOR_STATUS IOCTL tells the driver to perform any necessary steps to collect the current operating status of the device. Vendor-supplied WBDI drivers must support this IOCTL.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp**.**SystemBuffer** member points to a buffer that contains a [WINBIO_DIAGNOSTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_diagnostics) structure.

### Output buffer length

The length of a [WINBIO_DIAGNOSTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_diagnostics) structure.

The vendor-supplied driver can optionally return a DWORD-sized buffer that specifies the buffer size necessary for the requested operation.

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

If the vendor-supplied driver passes back the entire payload, it should fill in the **WinBioHresult** member of WINBIO_DIAGNOSTICS with the status of the Biometric operation.