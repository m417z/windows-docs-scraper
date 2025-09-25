# IOCTL_CDROM_SEND_OPC_INFORMATION IOCTL

## Description

The **IOCTL_CDROM_SEND_OPC_INFORMATION**
control code can be used in file systems and other implementations that want to perform the Optimum Power Calibration (OPC) procedure in advance, so that the first streaming write does not have to wait for the procedure to finish. The optical drive performs the OPC procedure to determine the optimum power of the laser during write. The procedure is necessary to ensure quality, but it wears out the media and should not be performed too often.

To perform this operation, call the
[DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
function with **IOCTL_CDROM_SEND_OPC_INFORMATION** as the *dwIoControlCode* parameter.

## Parameters

### Major code

### Input buffer

[CDROM_SIMPLE_OPC_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_simple_opc_info)

### Input buffer length

Length of a [CDROM_SIMPLE_OPC_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_simple_opc_info).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned.

Because of status code propagation from other APIs, the **Status** field can be set to (but is not limited to) the following:

**STATUS_INFO_LENGTH_MISMATCH**

The input buffer length is smaller than required.

**STATUS_INVALID_PARAMETER**

The request type is not **SimpleOpcInfo**.

**STATUS_SUCCESS**

The request completed successfully.

## Remarks

The **IOCTL_CDROM_SEND_OPC_INFORMATION** IOCTL is a wrapper over the SEND OPC INFORMATION command of the MMC specification. The **Exclude0** and **Exclude1** fields directly map to the SEND OPC INFORMATION fields with the same names.

On failures, this IOCTL returns standard errors, such as STATUS_DEVICE_NOT_READY, STATUS_IO_TIMEOUT, STATUS_IO_DEVICE_ERROR.

## See also

[CDROM_SIMPLE_OPC_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_simple_opc_info)

[DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)

[IOCTL_CDROM_SEND_OPC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_send_opc_information)