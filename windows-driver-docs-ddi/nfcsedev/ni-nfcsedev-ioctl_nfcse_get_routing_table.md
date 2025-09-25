# IOCTL_NFCSE_GET_ROUTING_TABLE IOCTL

## Description

Returns information regarding the current configuration of listen mode routing table. Note that the caller must allocate an output buffer large enough to hold information regarding all the entries that are present in the current listen mode routing table, i.e. Total number of routing entries x Size of routing table entry, otherwise the driver should return a STATUS_BUFFER_OVERFLOW error code to the client with NumberOfEntries field containing the number of routing table entries configured. The routing table entry is of type SECURE_ELEMENT_ROUTING_TABLE_ENTRY. Note: The driver shouldn’t return entry routing NFC-DEP to DH as part of the routing table returned in the output buffer even though the entry is present in the NFCC routing table.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

None

### Output buffer

 [SECURE_ELEMENT_ROUTING_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_routing_table) containing all currently configured routing entries.

### Output buffer length

sizeof(SECURE_ELEMENT_ROUTING_TABLE)

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Return Code | Description |
| --- | --- |
| **STATUS_BUFFER_OVERFLOW** | The buffer supplied was too small to receive the routing table configuration. |
| **STATUS_FEATURE_NOT_SUPPORTED** | The NFCC does not support listen mode routing configuration. |
| **STATUS_INVALID_PARAMETER** | This code is returned if the input buffer is non-zero. |
| **STATUS_INVALID_DEVICE_STATE** | This code is returned if the IOCTL is sent on a handle other than with relative name ‘SEManage’. |