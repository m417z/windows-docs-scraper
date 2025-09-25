# IOCTL_BTHX_WRITE_HCI IOCTL

## Description

IOCTL_BTHX_WRITE_HCI is used to write Bluetooth ACL Data and Commands to the transport layer.

## Parameters

### Major code

### Input buffer

Profile drivers should use KMDF and its [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) method to retrieve input parameters. For example, to get the input buffer:

`Status = WdfRequestRetrieveInputMemory(_Request, &ReqInMemory);`

The buffer describes a [BTHX_HCI_READ_WRITE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ns-bthxddi-_bthx_hci_read_write_context) structure that specifies the type of write and the data associated with the write.

Refer to the WDK Bluetooth samples for more information.

### Input buffer length

The length of the buffer is the size of the **BTHX_HCI_READ_WRITE_CONTEXT** structure.

### Output buffer

Profile drivers should use KMDF and its [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) method to retrieve input parameters. For example, to get the output buffer:

`Status = WdfRequestRetrieveOutputMemory(_Request, &ReqOutMemory);`

The buffer describes a ULONG of the number of bytes written for the input data specified in the **BTHX_HCI_READ_WRITE_CONTEXT** structure.

Refer to the WDK Bluetooth samples for more information.

### Output buffer length

The length of the buffer is the size of a ULONG.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful the
**Information** member of the STATUS_BLOCK structure is set to the number of bytes in the Output Parameter.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |

## Remarks

The Bluetooth stack sends IOCTL_BTHX_WRITE_HCI to write HCI ACL data and HCI command to the controller.

The input buffer points to a BTHX_HCI_READ_WRITE_CONTEXT structure whose **DataLen** member specifies the number of bytes in the **Data** member. The **Type** member is set based on whether the packet is a command packet or an ACL data packet.