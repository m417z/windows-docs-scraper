# SpbRequestGetTransferParameters function

## Description

The *SpbRequestGetTransferParameters* method retrieves the transfer parameters for an individual transfer in an [I/O transfer sequence](https://learn.microsoft.com/windows-hardware/drivers/spb/i-o-transfer-sequences).

## Parameters

### `SpbRequest` [in]

An [SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to the I/O request from which to retrieve the transfer parameters. This parameter must be a handle to an [IOCTL_SPB_EXECUTE_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_execute_sequence) request.

### `Index` [in]

The index of a transfer in the I/O transfer sequence. For more information, see the following Remarks section.

### `TransferDescriptor` [out, optional]

A pointer to a caller-allocated [SPB_TRANSFER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-spb_transfer_descriptor) structure into which the method writes the transfer parameters. The *TransferDescriptor* parameter is optional and can be specified as NULL if the caller does not require the transfer parameters. For more information, see the [Remarks](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbrequestgettransferparameters#remarks) section.

### `TransferBuffer` [out, optional]

A pointer to a location into which the method writes a pointer to an MDL (or an MDL chain) that describes the physical memory in the transfer buffer. The caller must not modify the contents of this MDL. This parameter is optional and can be set to NULL if the MDL is not needed. For more information, see the following Remarks section.

## Remarks

To request an I/O transfer sequence, a client (peripheral driver) of the SPB controller driver sends an [IOCTL_SPB_EXECUTE_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_execute_sequence) request that contains a list of the transfers in the sequence. Your controller driver can call *SpbRequestGetTransferParameters* to obtain information about a particular transfer in the sequence.

The *Index* parameter is an index that identifies a particular transfer in the sequence. If N is the number of transfers in the sequence, valid indexes range from 0 to N–1. To determine the number of transfers in the sequence, call the [SpbRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbrequestgetparameters) method. This method retrieves an [SPB_TRANSFER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-spb_transfer_descriptor) structure that contains the request parameters. The *TransferCount* member of this structure specifies the number of transfers in the sequence.

If *TransferDescriptor* is non-NULL, the caller must call the [SPB_TRANSFER_DESCRIPTOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_transfer_descriptor_init) function to initialize the structure before calling *SpbRequestGetTransferParameters*. After the structure is initialized, it can be reused as many times as needed without being reinitialized.

*TransferBuffer* is an optional pointer into which *SpbRequestGetTransferParameters* writes a pointer to an MDL that describes the physical page layout for the transfer buffer. The transfer buffer can be described by a single MDL or by an MDL chain. A simple buffer, which consists of a contiguous block of virtual memory, is described by a single MDL. If a transfer buffer is formatted as a scatter-gather list, each contiguous block of virtual memory in the buffer is described by an MDL in an MDL chain. For more information about MDLs, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

### Examples

```cpp
//
// Note that this snippet shows a transfer completing synchronously. This
// is a horrible thing for a driver to do, but demonstrates the DDI nicely.
//

WDF_REQUEST_PARAMETERS parameters;
WDF_TRANSFER_DESCRIPTOR transfer;

WDF_REQUEST_PARAMETERS_INIT(&parameters);
WDF_TRANSFER_DESCRIPTOR_INIT(&transfer);

SpbRequestGetParameters(request, &parameters);

for (ULONG i = 0; i < parameters.SequenceCount; i += 1)
{
    WDFMEMORY buffer;

    SpbRequestGetTransferParameters(request, i, &transfer, &buffer);

    MyDriverPerformTransfer(deviceContext,
                            request,
                            transfer,
                            buffer);
}
```

## See also

* [IOCTL_SPB_EXECUTE_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_execute_sequence)
* [SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)
* [SPB_TRANSFER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-spb_transfer_descriptor)
* [SPB_TRANSFER_DESCRIPTOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_transfer_descriptor_init)
* [SpbRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spbrequestgetparameters)