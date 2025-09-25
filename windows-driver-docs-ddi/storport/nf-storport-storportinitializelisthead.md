# StorPortInitializeListHead function

## Description

The **StorPortInitializeListHead** routine initializes a [**STOR_LIST_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_list_entry) structure that represents the head of a doubly linked list.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `ListHead` [out]

Pointer to the [**STOR_LIST_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_list_entry) structure that represents the head of the list.

## See also

[**InitializeListHead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializelisthead)

[**StorPortInterlockedInsertHeadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedinsertheadlist)

[**StorPortInterlockedInsertTailList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedinserttaillist)

[**StorPortInterlockedRemoveHeadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedremoveheadlist)