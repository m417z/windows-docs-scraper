# IOCTL_BIOMETRIC_GET_SUPPORTED_ALGORITHMS IOCTL

## Description

The IOCTL_BIOMETRIC_GET_SUPPORTED_ALGORITHMS IOCTL retrieves a list of cryptographic hash algorithms that are supported by the device. This IOCTL is optional.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp**.**SystemBuffer** member points to a buffer that contains a [WINBIO_SUPPORTED_ALGORITHMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_supported_algorithms) structure.

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

The algorithms are specified by using NULL-terminated UTF-8 encoded strings. The algorithm identifier "OID" strings are defined in [RFC 3279](https://go.microsoft.com/fwlink/p/?linkid=133011)  and [RFC 3278](https://go.microsoft.com/fwlink/p/?linkid=133012) .

Here are examples of OID strings for hash algorithms.

|Algorithm|Algorithm identifier string|
|--- |--- |
|SHA-1|"1.3.14.3.2.26"|
|SHA-256|"2.16.840.1.101.3.4.2.1"|
|SHA-384|"2.16.840.1.101.3.4.2.2"|
|SHA-512|"2.16.840.1.101.3.4.2.3"|

IOCTL_BIOMETRIC_GET_SUPPORTED_ALGORITHMS must be implemented if the device supports WINBIO_CAPABILITY_SECURE_STORAGE. The device must support at least SHA-1 ("1.3.14.3.2.26") to be used for storing WinBio templates.

If the vendor-supplied driver passes back the entire payload, it should fill in the **WinBioHresult** member of [WINBIO_SUPPORTED_ALGORITHMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_supported_algorithms) with the status of the Biometric operation.

Possible values include: