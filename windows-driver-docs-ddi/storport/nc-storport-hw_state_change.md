# HW_STATE_CHANGE callback function

## Description

A miniport-provided callback that is called after a notification from [**StorPortStateChangeDetected**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportstatechangedetected) is processed.

## Parameters

### `HwDeviceExtension`

[in] A pointer to the miniport driver's per-HBA storage area.

### `Context` [in, optional]

The context supplied as **HwStateChangeContext** by the miniport in the call to [**StorPortStateChangeDetected**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportstatechangedetected).

### `AddressType` [in]

The type of the address in **Address**.

### `Address` [in]

A pointer to a [**STOR_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_address) structure for the entity whose state change was processed.

### `Status` [in]

The processing status for the state change notification.

## Remarks

The **HwStorStateChange** is called with the StartIo lock acquired by Storport.

This callback enables miniports to do any additional processing that is needed after hardware addition or removal. If a hardware change occurs on the HBA port or bus, the miniport can call [**StorPortStateChangeDetected**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportstatechangedetected) to alert the system of the event.

If the value for **Status** is < 0x80000000, then the notification processing was successful. Otherwise, the notification process failed.

The name **HwStorStateChange** is just a placeholder for the miniport function that is pointed to by the **HwStateChange** parameter of [**StorPortStateChangeDetected**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportstatechangedetected). The actual prototype of this routine is defined in *Storport.h* as follows:

``` c
typedef
VOID
HW_STATE_CHANGE (
    _In_ PVOID HwDeviceExtension,
    _In_opt_ PVOID Context,
    _In_ SHORT AddressType,
    _In_ PVOID Address,
    _In_ ULONG Status
    );
```

## See also

[**STOR_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_address)

[**StorPortStateChangeDetected**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportstatechangedetected)