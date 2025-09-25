# IOCTL_BTHX_READ_HCI IOCTL

## Description

IOCTL_BTHX_READ_HCI is used to read Bluetooth ACL Data and Events from the transport layer.

## Parameters

### Major code

### Input buffer

Profile drivers should use KMDF and its [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) method to retrieve input parameters. For example, to get the output buffer:

`Status = WdfRequestRetrieveInputMemory(_Request, &ReqInMemory);`

For more information, see the WDK Bluetooth samples.

### Input buffer length

The buffer describes a UCHAR that represents the type of read. The length of the buffer is the size of the UCHAR.

### Output buffer

Profile drivers should use KMDF and its [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) method to retrieve input parameters. For example, to get the output buffer:

`Status = WdfRequestRetrieveOutputMemory(_Request, &ReqOutMemory);`

For more information, see the WDK Bluetooth samples.

### Output buffer length

The
**AssociatedIrp.SystemBuffer** member points to a buffer that holds a [BTHX_HCI_READ_WRITE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ns-bthxddi-_bthx_hci_read_write_context) structure and additional data associated with the read. The buffer must be large enough to hold the largest event or ACL Data packet, depending on its packet type.

For an event packet, it is FIELD_OFFSET(BTHX_HCI_READ_WRITE_CONTEXT, Data) +257 where 257 is the sum of a 2-byte event header and 255-byte event data.

For an ACL Data packet, it is FIELD_OFFSET(BTHX_HCI_READ_WRITE_CONTEXT, Data) + MaxAclTransferInSize where MaxAclTransferInSize is the value in BTHX_CAPABILITIES that is returned from the transport driver with IOCTL_BTHX_QUERY_CAPABILITIES.

### Input/output buffer

### Input/output buffer length

### Status block

The
**Information** member of the STATUS_BLOCK structure is set to the number of bytes of data returned.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |
| STATUS_CANCELLED | The IOCTL has been canceled. |

## Remarks

The input buffer points to the type of packet that is being read.

The output buffer points to a BTHX_HCI_READ_WRITE_CONTEXT structure whose **DataLen** member specifies the number of bytes in the **Data** member. The **Type** member must be set to the same as the Input packet type.

The **Information** member of the STATUS_BLOCK should be set to FIELD_OFFSET(BTHX_HCI_READ_WRITE_CONTEXT, Data) + **DataLen**.

The maximum size of the **Data** member for an ACL read is determined by **MaxAclTransferInSize**, specified in the BTHX_CAPABILITIES structure. The maximum size of the **Data** member for an event is 255.

This IOCTL should return STATUS_SUCCESS only under normal operation. Transport-specific errors should not be returned. The IOCTL should return STATUS_CANCELLED only if this IOCTL has been canceled.