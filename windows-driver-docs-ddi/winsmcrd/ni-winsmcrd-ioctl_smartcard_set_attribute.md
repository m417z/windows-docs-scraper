# IOCTL_SMARTCARD_SET_ATTRIBUTE IOCTL

## Description

The **IOCTL_SMARTCARD_SET_ATTRIBUTE** control code sets various attributes in a smart card reader driver and returns STATUS_SUCCESS on SCARD_ATTR_DEVICE_IN_USE; otherwise, it returns STATUS_NOT_SUPPORTED.

## Parameters

### Major code

### Input buffer

(DWORD) contains the attribute identifier.

* **Irp->AssociatedIrp.SystemBuffer**
Contains the tag and value to set.

* **Parameters.DeviceIoControl.InputBufferLength**
Contains the length of the tag-length value (TLV) structure.

### Input buffer length

### Output buffer

None.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Information** must be set to sizeof(ULONG).

**Irp->IoStatus.Status** is set to one of the following values.

| Value | Meaning |
| ----- | ------- |
| STATUS_SUCCESS | The attribute has been set successfully. |
| STATUS_NOT_SUPPORTED | The attribute is not supported. |
| STATUS_INVALID_PARAMETER | The attribute to set is in the wrong format.
| STATUS_DEVICE_POWERED_OFF | The proximity radio control is off. |

## See also

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)

[Smart card design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/design-guide-smart-card)