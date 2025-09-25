# _SERCX2_CUSTOM_RECEIVE_CONFIG structure

## Description

The **SERCX2_CUSTOM_RECEIVE_CONFIG** structure contains information that version 2 of the serial framework extension (SerCx2) uses to configure a new custom-receive object.

## Members

### `Size`

The size, in bytes, of this structure. The [SerCx2CustomReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivecreate) method uses this member to determine which version of the structure the caller is using. The size of this structure might change in future versions of the Sercx.h header file.

### `Alignment`

Data alignment requirement. Specifies how the starting address of a transfer in a custom-receive transaction must be aligned in memory. Set this member to the appropriate FILE_*XXX*_ALIGNMENT constant in the Wdm.h header file. For example, FILE_WORD_ALIGNMENT indicates that the starting address must be aligned to two-byte boundary in memory, FILE_LONG_ALIGNMENT indicates that the address must be aligned to a four-byte boundary, and so on.

### `MinimumTransactionLength`

The minimum length, in bytes, of a data transfer in a custom-receive transaction. If the length of the buffer in a read ([IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)) request is less than this minimum length, SerCx2 uses programmed I/O (PIO) for the transaction.

### `MaximumTransactionLength`

The maximum length, in bytes, of a data transfer in a custom-receive transaction. If the size of the buffer in the read request is larger than this maximum length, SerCx2 uses multiple custom-receive transactions to handle the request, and limits each transaction to the maximum length.

### `MinimumTransferUnit`

The minimum transfer unit. The number of bytes specified by an element in a scatter/gather list must be an integer multiple of the minimum transfer unit. To indicate that the default minimum transfer unit should be used, set this member to zero. For more information about the default minimum transfer unit, see [DMA_ADAPTER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info_v1).

### `Exclusive`

Whether to use custom-receive transactions exclusively to handle write ([IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)) requests. Set to **TRUE** to indicate that read requests should use custom-receive transactions exclusively. Set to **FALSE** to indicate that read requests can use a combination of custom-receive transactions and PIO-receive transactions.

Set this member to **TRUE** only if the minimum transfer unit for custom-receive transactions is one byte, the minimum transaction length is one byte, and the read buffer for the transaction can start on any byte boundary in memory.

If **Exclusive** is **TRUE**, the **MinimumTransferUnitOverride**, **Alignment**, and **MinimumTransactionLength** members must be zero.

Regardless of the value of this member, PIO-receive transactions are used to save any unread data in the receive FIFO before the serial controller exits the D0 device power state to enter a low-power state.

## Remarks

The [SerCx2CustomReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivecreate) method accepts a pointer to a **SERCX2_CUSTOM_RECEIVE_CONFIG** structure as an input parameter. Before calling **SerCx2CustomReceiveCreate**, call the [SERCX2_CUSTOM_RECEIVE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_custom_receive_config_init) function to initialize this structure.

## See also

[DMA_ADAPTER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter_info_v1)

[IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)

[SERCX2_CUSTOM_RECEIVE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_custom_receive_config_init)

[SerCx2CustomReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2customreceivecreate)