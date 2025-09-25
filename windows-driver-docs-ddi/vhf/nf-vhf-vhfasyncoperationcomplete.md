# VhfAsyncOperationComplete function

## Description

The HID source driver calls this method to set the results of an asynchronous operation.

## Parameters

### `VhfOperationHandle` [in]

The operation handle set by Virtual HID Framework (VHF). This handle is passed to the HID source driver in the *VhfOperationHandle* parameter of [EvtVhfAsyncOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nc-vhf-evt_vhf_async_operation).

### `CompletionStatus` [in]

If the operation succeeds, the method returns STATUS_SUCCESS. Otherwise an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)  value.

## Return value

If the **VhfAsyncOperationComplete** call succeeds, the method returns STATUS_SUCCESS. Otherwise an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)  value.

## Remarks

The HID source driver can call from the event callback or at a later time after returning from the [EvtVhfAsyncOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/vhf/nc-vhf-evt_vhf_async_operation) callback.

## See also

[Write a HID source driver by using Virtual HID Framework (VHF)](https://learn.microsoft.com/windows-hardware/drivers/hid/virtual-hid-framework--vhf-)