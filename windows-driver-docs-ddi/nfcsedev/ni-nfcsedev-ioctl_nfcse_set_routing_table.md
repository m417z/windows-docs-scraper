# IOCTL_NFCSE_SET_ROUTING_TABLE IOCTL

## Description

Configures NFC controller listen mode routing table. Note that caller has to send complete listen mode routing information in a single call. The caller shall ensure that routing table is less than the cbMaxRoutingTableSize value defined in 4.2.5.1. The total size is computed as per NFC NCI standard sec 6.3.2 and is equal to Number of AID based routes x 4 + sum of cbAid + Number of technology based routes x 5 + Number of protocol based routes x 5. The caller shall ensure that values for technology- and protocol-based routes are conformant to NCI NFC spec sec 6.3.2.

## Parameters

### Major code

### Input buffer

 [SECURE_ELEMENT_ROUTING_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_routing_table) containing all currently configured routing entries.

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Return Code | Description |
| --- | --- |
| **STATUS_INVALID_BUFFER_SIZE** | The buffer supplied was greater than NFC controller MAX_ROUTING_TABLE_SIZE. |
| **STATUS_FEATURE_NOT_SUPPORTED** | The NFCC does not support listen mode routing configuration. |
| **STATUS_INVALID_PARAMETER** | This status is returned if the output buffer is non-zero, or values used for technology or protocol is conformant to NFC NCI spec sec 6.3.2, or if duplicate AIDs are used, or when using routing mode that is not supported by current NFC controller capabilities. |
| **STATUS_INVALID_DEVICE_STATE** | This code is returned if the IOCTL is sent on a handle other than with relative name ‘SEManage’. |

## Remarks

The following are requirements that the driver must adhere to.

* This IOCTL is sent on a handle with a ‘SEManage’ relative file name, otherwise the driver MUST complete it with STATUS_INVALID_DEVICE_STATE.
* The driver shall have initial default listen mode routing table entries that route RF technologies A, B, and F and/or ISO-DEP protocol routed to UICC SE if present. These routing entries may later be overridden by new listen mode routing table configuration initiated by device host.
* The driver shall ensure that protocol NFC-DEP is mapped to device host at all times. Even if the caller doesn’t specify this, the driver needs to add this rule implicitly.
* If this IOCTL is issued when the NFCC is in RF discovery state, the driver needs to put the NFCC into RF idle state, configure the routing table, and restart RF discovery.