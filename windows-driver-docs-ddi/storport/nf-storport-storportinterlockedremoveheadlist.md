# StorPortInterlockedRemoveHeadList function

## Description

The StorPortInterlockedRemoveHeadList routine removes an entry from the beginning of a doubly linked list of [**STOR_LIST_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_list_entry) structures.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `ListHead` [in, out]

Pointer to the [**STOR_LIST_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_list_entry) structure that represents the head of the list.

### `Result` [in, out]

Pointer to a [**STOR_LIST_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_list_entry) structure that represents the entry removed from the list. If the list was empty, the routine returns **NULL**.

### `Lock` [in, out]

A pointer to a **STOR_KSPIN_LOCK** structure that serves as the spin lock used to synchronize access to the list. The storage for the spin lock must be resident and must have been initialized by calling [**StorPortInitializeSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializespinlock).

 You must use this spin lock only with the **StorPortInterlocked*Xxx*List** routines.

## Return value

**StorPortInterlockedRemoveHeadList** returns one of the following status codes:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_NOT_IMPLEMENTED | This function is not implemented on the active operating system. |
| STOR_STATUS_SUCCESS | The list items were removed successfully or the list is already empty. |
| STOR_STATUS_INVALID_PARAMETER | A pointer in **ListHead** or **Result** is **NULL**. |

## See also

[**InitializeListHead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-initializelisthead)

[**InsertHeadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-insertheadlist)

[**StorPortInitializeSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializespinlock)

[**StorPortInterlockedInsertHeadList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedinsertheadlist)

[**StorPortInterlockedInsertTailList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinterlockedinserttaillist)