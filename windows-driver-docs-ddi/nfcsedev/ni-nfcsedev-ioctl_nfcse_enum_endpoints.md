# IOCTL_NFCSE_ENUM_ENDPOINTS IOCTL

## Description

 Returns information regarding the list of all the secure elements attached to the NFC controller. Note that the caller must allocate an output buffer large enough to hold information regarding all the secure elements that were enumerated by the driver i.e. Total number of SEs Enumerated x Size of the SE endpoint info otherwise the driver should return a STATUS_BUFFER_OVERFLOW error code to the client with the NumberOfEndpoints field containing the number of secure elements enumerated. The GUID identifying the secure element which maybe used to refer to a particular secure element.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

None

### Output buffer

An  [SECURE_ELEMENT_ENDPOINT_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_endpoint_list) for each device enumerated.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Return Code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | This code is returned when the output buffer is non-zero. |
| **STATUS_BUFFER_OVERFLOW** | The buffer supplied was too small to receive the routing table configuration. |

## Remarks

The following are requirements that the driver must adhere to.

* In the case of integrated secure element the GUID shall be a unique identifier derived from the serial number and/or other unique identification of the secure element.
* For external secure elements, the GUID maybe a fixed constant and identifies only the “socket” into which the secure element is connected.
* For device host secure element, the driver shall enumerate it as a SE end point only if it supports Host Card Emulation. The GUID used for DH maybe a fixed constant defined by the driver.
* The caller is required to allocate an output buffer large enough to hold the information about all the secure elements that were enumerated by the driver. The buffer must be equal to the total number of SEs enumerated by the driver multiplied by the size of the SE endpoint information. If the appropriate buffer isn’t allocated, the driver returns a STATUS_BUFFER_OVERFLOW error code to the client with the NumberOfEndpoints field that contains the number of secure elements enumerated.