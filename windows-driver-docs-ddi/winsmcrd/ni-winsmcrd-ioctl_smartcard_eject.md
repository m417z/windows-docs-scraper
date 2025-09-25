# IOCTL_SMARTCARD_EJECT IOCTL

## Description

The IOCTL_SMARTCARD_EJECT request ejects the currently inserted smart card from the smart card reader.

## Parameters

### Major code

### Input buffer

None

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
| STATUS_NO_MEDIA | No smart card is in the reader. |
| STATUS_NOT_SUPPORTED | Reader does not support smart card eject. |
| STATUS_IO_TIMEOUT | Operation timed out. |