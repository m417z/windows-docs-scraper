# IOCTL_NFCSE_GET_NFCC_CAPABILITIES IOCTL

## Description

The **IOCTL_NFCSE_GET_NFCC_CAPABILITIES**
control code returns information about the current NFC controller capabilities, including the maximum Listen Mode Routing table size (defined in section 4.2 of the *NFC Controller Interface (NCI) Technical Specification Version 1.1)* and supported routing modes.

## Parameters

### Major code

### Input buffer

None

### Input buffer length

None

### Output buffer

 [SECURE_ELEMENT_NFCC_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_nfcc_capabilities) containing NFC controller capabilities.

### Output buffer length

sizeof(SECURE_ELEMENT_NFCC_CAPABILITIES)

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Return Code | Description |
| --- | --- |
| **STATUS_BUFFER_OVERFLOW** | The buffer supplied was too small for the SECURE_ELEMENT_NFCC_CAPABILITIES structure. |
| **STATUS_INVALID_PARAMETER** | If the input buffer is non-zero. |
| **STATUS_INVALID_DEVICE_STATE** | If the IOCTL is sent on a handle other than with the relative name 'SEManage'. |