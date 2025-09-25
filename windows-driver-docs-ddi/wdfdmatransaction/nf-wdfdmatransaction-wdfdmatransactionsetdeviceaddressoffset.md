# WdfDmaTransactionSetDeviceAddressOffset function

## Description

[Applies to KMDF only]

 The
**WdfDmaTransactionSetDeviceAddressOffset** method specifies the offset of the register that the system DMA controller will access when performing the DMA operation.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that specifies the transaction to modify.

### `Offset` [in]

The offset of the register, from the **DeviceAddress** specified in [WDF_DMA_SYSTEM_PROFILE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_system_profile_config), to or from which DMA should be performed.

## Remarks

**WdfDmaTransactionSetDeviceAddressOffset** must be used with a DMA enabler that specifies a system-mode DMA profile.

Framework-based drivers call **WdfDmaTransactionSetDeviceAddressOffset** after initializing a DMA transaction and before executing it.

A driver can use this method to access multiple registers within a device's register file.

For example, a driver might use DMA to access separate read and write registers in a device's register file.

To do so, the driver specifies the base address of the device's register file when configuring the enabler, and then sets the offset of the read or write register as necessary before executing the transaction.

If your driver calls this method on an operating system earlier than Windows 8, [the framework's verifier](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-kmdf-verifier) reports an error.

#### Examples

The following code example initializes a DMA transaction. It then sets the offset of the register that the system DMA controller will access, provides a transfer completion callback routine, and executes the DMA transaction.

```cpp
status = WdfDmaTransactionInitialize(
                                     RequestContext->DmaTransaction,
                                     EvtProgramDma,
                                     direction,
                                     mdl,
                                     startingVa,
                                     length
                                     );

if(!NT_SUCCESS(status)) {
    goto Complete;
}

WdfDmaTransactionSetDeviceAddressOffset(
                                        RequestContext->DmaTransaction,
                                        READ_DATA_REGISTER_OFFSET
                                        );

WdfDmaTransactionSetTransferCompleteCallback(
                                             RequestContext->DmaTransaction,
                                             EvtDmaTransactionDmaTransferComplete,
                                             RequestContext
                                             );

status = WdfDmaTransactionExecute(
                                  RequestContext->DmaTransaction,
                                  RequestContext );

if(!NT_SUCCESS(status)) {
    goto Complete;
}

return status;

Complete:

WdfDmaTransactionRelease(
                         RequestContext->DmaTransaction
                         );
```

## See also

[WDF_DMA_SYSTEM_PROFILE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_system_profile_config)