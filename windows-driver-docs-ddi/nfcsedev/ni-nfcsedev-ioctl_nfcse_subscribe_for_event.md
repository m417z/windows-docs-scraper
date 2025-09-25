# IOCTL_NFCSE_SUBSCRIBE_FOR_EVENT IOCTL

## Description

The **IOCTL_NFCSE_SUBSCRIBE_FOR_EVENT**
control code is issued by a client to subscribe to a specific event.

## Parameters

### Major code

### Input buffer

 [SECURE_ELEMENT_EVENT_SUBSCRIPTION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_event_subscription_info) structure.

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
| **STATUS_INVALID_DEVICE_STATE** | This code is returned when this IOCTL is called on a device handle with a filename other than **SEEvents**, or there is already another pending request that is not completed yet. |
| **STATUS_FEATURE_NOT_SUPPORTED** | This code is returned when the output is non-zero, or when the GUID of the secure element does not match any of the enumerated IDs. |

## Remarks

The following are requirements that the driver must adhere to.

* This IOCTL must be called on a handle with a **SEEvents** file name; otherwise, the driver returns STATUS_INVALID_DEVICE_STATE.
* **GUID_NULL** can be specified by the client as a wild card to subscribe for a specific event from all enumerated secure elements.