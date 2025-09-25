# SPB_TRANSFER_LIST_INIT function

## Description

The **SPB_TRANSFER_LIST_INIT** function initializes an [SPB_TRANSFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list) structure.

## Parameters

### `TransferList` [out]

A pointer to the **SPB_TRANSFER_LIST** structure that is to be initialized.

### `TransferCount` [in]

The number of entries in the transfer list. The function writes this value to the **TransferCount** member of the **SPB_TRANSFER_LIST** structure.

## Remarks

To initialize the elements in the **SPB_TRANSFER_LIST** structure's **Transfers** array, use the [SPB_TRANSFER_LIST_ENTRY_INIT_SIMPLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_transfer_list_entry_init_simple), [SPB_TRANSFER_LIST_ENTRY_INIT_NON_PAGED](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_transfer_list_entry_init_non_paged), or [SPB_TRANSFER_LIST_ENTRY_INIT_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_transfer_list_entry_init_buffer_list) function.

## See also

- [SPB_TRANSFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list)
- [SPB_TRANSFER_LIST_ENTRY_INIT_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_transfer_list_entry_init_buffer_list)
- [SPB_TRANSFER_LIST_ENTRY_INIT_NON_PAGED](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_transfer_list_entry_init_non_paged)
- [SPB_TRANSFER_LIST_ENTRY_INIT_SIMPLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_transfer_list_entry_init_simple)