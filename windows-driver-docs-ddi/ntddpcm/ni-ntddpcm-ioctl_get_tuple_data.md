# IOCTL_GET_TUPLE_DATA IOCTL

## Description

This request retrieves tuple data that is stored in a PC Card's or CardBus card's attribute memory. The caller must specify the number of the socket where the PC Card or CardBus card is inserted, the location of an output buffer, and the number of bytes of tuple data to be read.

## Parameters

### Major code

### Input buffer

The caller initializes the [TUPLE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/ns-ntddpcm-_tuple_request) structure, which is defined in *ntddpcm.h*, at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the input buffer, which must be greater than or equal to **sizeof**(TUPLE_REQUEST).

### Output buffer

The PCMCIA bus driver stores the requested tuple data at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

The size of the requested tuple data.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes read.

If the operation is successful, the **Status** field is set to STATUS_SUCCESS.

If **InputBufferLength** is less than **sizeof**(TUPLE_REQUEST), the **Status** field is set to STATUS_INVALID_PARAMETER.

If the bus driver cannot identify a socket that is associated with the socket number indicated in TUPLE_REQUEST, the **Status** field is set to STATUS_INVALID_PARAMETER.

If there is no card in the indicated socket, the **Status** field is set to STATUS_UNSUCCESSFUL.

## See also

[IRP_MN_READ_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-read-config)

[IRP_MN_WRITE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-write-config)

[TUPLE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/ns-ntddpcm-_tuple_request)