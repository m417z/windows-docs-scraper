# IOCTL_NFCSE_HCE_REMOTE_SEND IOCTL

## Description

Transmits response APDU from DeviceHost NFCEE to remote device. The caller must be sure that response APDU is conformant to ISO-IEC 7816-4.

## Parameters

### Major code

### Input buffer

Pointer to buffer containing [SECURE_ELEMENT_HCE_DATA_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_hce_data_packet) structure.

### Input buffer length

sizeof(SECURE_ELEMENT_HCE_DATA_PACKET)

### Output buffer

None

### Output buffer length

None

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Return Code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | This code is returned if the input connection ID does not match the current connection ID. |
| **STATUS_INVALID_DEVICE_STATE** | This code is returned if the IOCTL is sent on a handle other than with relative name ‘SEManage’. |