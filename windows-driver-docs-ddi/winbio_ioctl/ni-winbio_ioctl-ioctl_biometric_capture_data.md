# IOCTL_BIOMETRIC_CAPTURE_DATA IOCTL

## Description

The IOCTL_BIOMETRIC_CAPTURE_DATA IOCTL directs the driver to retrieve the next scan of biometric data. This call should put the device into capture mode.Vendor-supplied WBDI drivers must support IOCTL_BIOMETRIC_CAPTURE_DATA.

## Parameters

### Major code

### Input buffer

[WINBIO_CAPTURE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_capture_parameters)

### Input buffer length

The length of a [WINBIO_CAPTURE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_capture_parameters)
structure.

### Output buffer

The **AssociatedIrp**.**SystemBuffer** member points to a buffer that contains a [WINBIO_CAPTURE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_capture_data) structure.

The vendor-specific data in the WINBIO_BIR structure can be in any format the vendor would like to collect from the driver. Vendors can choose to process data in the WBDI driver or in the engine adapter, but the data must be passed in one structure.

### Output buffer length

The smallest valid output buffer size is the size of DWORD.

If the driver receives a DWORD-sized output buffer, the driver must immediately return the buffer size necessary to complete the operation. Do not wait for the swipe to occur to send the required buffer size.

### Input/output buffer

### Input/output buffer length

### Status block

Indicates whether the DeviceIoControl call to the driver completed and the OUT payload is valid.

The **Status** member is set to one of the values in the following table.

|Status value|Description|
|--- |--- |
|S_OK, STATUS_SUCCESS|The operation completed successfully. If the size of data returned is DWORD, the payload contains the size of the buffer necessary for the call. Otherwise, the payload contains the full output buffer.|
|E_INVALIDARG|The parameters were not specified correctly.|
|WINBIO_E_DATA_COLLECTION_IN_PROGRESS|Device has an IOCTL_BIOMETRIC_CAPTURE_DATA pending.|
|E_UNKNOWN|Any other failure that prevents the payload from being filled in.|
|E_UNEXPECTED|Any other failure that prevents the payload from being filled in.|
|E_FAIL|Any other failure that prevents the payload from being filled in.|

## Remarks

Only one data collection IOCTL can be pending at any time. If the device has an IOCTL_BIOMETRIC_CAPTURE_DATA pending, IOCTL_BIOMETRIC_CAPTURE_DATA must return WINBIO_E_DATA_COLLECTION_IN_PROGRESS.

IOCTL_BIOMETRIC_CAPTURE_DATA is a blocking data collection IOCTL that is completed when the biometric data capture occurs.

If the vendor-supplied driver passes back the entire payload, it should fill in the **WinBioHresult** member of WINBIO_CAPTURE_DATA with the status of the Biometric operation.

Possible values include: