# IOCTL_SOCKET_INFORMATION IOCTL

## Description

This request retrieves socket information for the socket that is indicated by the caller.

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the input buffer, which must be greater than or equal to **sizeof**(PCMCIA_SOCKET_INFORMATION).

The caller initializes the **Socket** member of the [PCMCIA_SOCKET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/ns-ntddpcm-_pcmcia_socket_information) structure at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the input buffer, which must be greater than or equal to **sizeof**(PCMCIA_SOCKET_INFORMATION).

### Output buffer

The PCMCIA bus driver stores the requested socket data in a structure of type [PCMCIA_SOCKET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/ns-ntddpcm-_pcmcia_socket_information) at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

The size of the requested socket data.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes read.

If the operation is successful, the **Status** field is set to STATUS_SUCCESS.

If **InputBufferLength** is less than **sizeof**(PCMCIA_SOCKET_INFORMATION), the **Status** field is set to STATUS_BUFFER_TOO_SMALL.

If **OutputBufferLength** is less than **sizeof**(PCMCIA_SOCKET_INFORMATION), the **Status** field is set to STATUS_BUFFER_TOO_SMALL.

If the bus driver cannot identify a socket that is associated with the socket number indicated in [PCMCIA_SOCKET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/ns-ntddpcm-_pcmcia_socket_information), the **Status** field is set to STATUS_INVALID_PARAMETER.

If there is no card in the indicated socket, the **Status** field is set to STATUS_UNSUCCESSFUL.

## See also

[PCMCIA_SOCKET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/ns-ntddpcm-_pcmcia_socket_information)