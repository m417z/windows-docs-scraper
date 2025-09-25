# DXGKDDI_SET_POWER_STATE callback function

## Description

The *DxgkDdiSetPowerState* function sets the power state of a display adapter or a child device of a display adapter.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `DeviceUid` [in]

A positive integer that identifies the device for which the power state is to be set. If *DeviceUid* is equal to **DISPLAY_ADAPTER_HW_ID** (defined in Video.h), the device is the display adapter itself. Otherwise, *DeviceUid* is the identifier of a child device of the display adapter. Child device identifiers were previously assigned by the [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations) function.

### `DevicePowerState` [in]

A [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state) enumeration value that supplies the power state (**PowerDeviceD0**, **PowerDeviceD1**, **PowerDeviceD2**, **PowerDeviceD3**) to which the device should be set.

### `ActionType` [in]

A [POWER_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-power_action) enumeration value that supplies the reason (**PowerActionSleep**, **PowerActionHibernate**, **PowerActionShutdown**) for the power state change.

## Return value

*DxgkDdiSetPowerState* returns **STATUS_SUCCESS** if it succeeds. *DxgkDdiSetPowerState* should never fail; however, it can return any NTSTATUS-typed value that is defined in *Ntstatus.h* and that passes the [NT_SUCCESS(Status)](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) macro.

## Remarks

If the requested state is equal to **PowerDeviceD1**, **PowerDeviceD2**, or **PowerDeviceD3**, *DxgkDdiSetPowerState* saves any context that will later be required to bring the device back to **PowerDeviceD0** and then places the device in the requested state. If the requested state is **PowerDeviceD0** (fully on), *DxgkDdiSetPowerState* restores the device context and places the device in **PowerDeviceD0**.

If *DxgkDdiSetPowerState* is called with a request to put the VGA-enabled display adapter into hibernation, it should not power down the display adapter. Instead, it should save the context and let the bus driver power down the display adapter. That way, the power manager can display hibernation progress after the display miniport driver has been notified about the power state change.

The operating system might call *DxgkDdiSetPowerState* on a child device of the display adapter that is no longer connected (for example, a monitor that was recently unplugged). This anomaly occurs because an inherent latency exists between the time that the operating system calls the driver's *DxgkDdiSetPowerState* and the time that the operating system processes the disconnection. The driver must handle such situations without failing.

If *DevicePowerState* is equal to **PowerDeviceD0**, do not rely on the value of *ActionType*.

Starting with Windows Display Driver Model (WDDM) 1.2, if the *DevicePowerState* parameter is set to **PowerDeviceD0**, the display miniport driver should call [DxgkCbAcquirePostDisplayOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_acquire_post_display_ownership) to query the information about the display mode. This display mode might have been previously set by the firmware and system loader. If **DxgkCbAcquirePostDisplayOwnership** returns with **STATUS_SUCCESS**, the driver should determine whether it has to reinitialize the display based on the display mode information that was returned through the *DisplayInfo* parameter. Otherwise, the driver should not assume that any specific display mode is currently enabled on the device, and it should initialize the display.

The *DxgkDdiSetPowerState* function should be made pageable.

## See also

[DxgkCbAcquirePostDisplayOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_acquire_post_display_ownership)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)