# _SERCX2_CUSTOM_TRANSMIT_CONFIG structure

## Description

The **SERCX2_CUSTOM_TRANSMIT_CONFIG** structure contains information that version 2 of the serial framework extension (SerCx2) uses to configure a new custom-transmit object.

## Members

### `Size`

The size, in bytes, of this structure. The [SerCx2CustomTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmitcreate) method uses this member to determine which version of the structure the caller is using. The size of this structure might change in future versions of the Sercx.h header file.

### `Alignment`

Data alignment requirement. Specifies how the starting address of a transfer in a custom-transmit transaction must be aligned in memory. Set this member to the appropriate FILE_*XXX*_ALIGNMENT constant in the Wdm.h header file. For example, FILE_WORD_ALIGNMENT indicates that the starting address must be aligned to two-byte boundary in memory, FILE_LONG_ALIGNMENT indicates that the address must be aligned to a four-byte boundary, and so on.

### `MinimumTransactionLength`

The minimum length, in bytes, of a data transfer in a custom-transmit transaction. If the length of the buffer in a write ([IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) request is less than this minimum length, SerCx2 uses programmed I/O (PIO) for the transaction.

### `MaximumTransactionLength`

The maximum length, in bytes, of a data transfer in a custom-transmit transaction. If the size of the buffer in the write request is larger than this maximum length, SerCx2 uses multiple custom-transmit transactions to handle the request, and limits each transaction to the maximum length.

### `MinimumTransferUnit`

The minimum transfer unit. The number of bytes to transfer in a custom-transmit transaction must be an integer multiple of the minimum transfer unit. To indicate that the default minimum transfer unit should be used, set this member to zero. For more information about the default minimum transfer unit, see [DMA_ADAPTER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info_v1).

### `Exclusive`

Whether to use custom-transmit transactions exclusively to handle write ([IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) requests. Set to **TRUE** to indicate that write requests should use custom-transmit transactions exclusively. Set to **FALSE** to indicate that write requests can use a combination of custom-transmit transactions and PIO-transmit transactions.

Set this member to **TRUE** only if the minimum transfer unit for custom-transmit transactions is one byte, the minimum transaction length is one byte, and the write buffer for the transaction can start on any byte boundary in memory.

If **Exclusive** is **TRUE**, the **MinimumTransferUnit**, **Alignment**, and **MinimumTransactionLength** members must be zero.

## Remarks

The [SerCx2CustomTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmitcreate) method accepts a pointer to a **SERCX2_CUSTOM_TRANSMIT_CONFIG** structure as an input parameter. Before calling **SerCx2CustomTransmitCreate**, call the [SERCX2_CUSTOM_TRANSMIT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_custom_transmit_config_init) function to initialize this structure.

## See also

[DMA_ADAPTER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info_v1)

[IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)

[SERCX2_CUSTOM_TRANSMIT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_custom_transmit_config_init)

[SerCx2CustomTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customtransmitcreate)