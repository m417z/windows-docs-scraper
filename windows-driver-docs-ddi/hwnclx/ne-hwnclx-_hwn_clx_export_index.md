# _HWN_CLX_EXPORT_INDEX enumeration

## Description

Defines the position for each of the Hardware Notification exports in the export table.

## Constants

### `RegisterClientIndex`

Position of the [HwNRegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nf-hwnclx-hwnregisterclient) hardware notification in the export table.

### `UnregisterClientIndex`

Position of the [HwNUnregisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nf-hwnclx-hwnunregisterclient) hardware notification in the export table.

### `AddDevicePreDeviceCreateIndex`

Position of the [HwNProcessAddDevicePreDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nf-hwnclx-hwnprocessadddevicepredevicecreate) hardware notification in the export table.

### `AddDevicePostDeviceCreateIndex`

Position of the [HwNProcessAddDevicePostDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nf-hwnclx-hwnprocessadddevicepostdevicecreate) hardware notification in the export table.

### `HwNExportLastExportIndex`

Position of the last hardware notification in the export table.

## Syntax

```cpp
typedef enum _HWN_CLX_EXPORT_INDEX {
  RegisterClientIndex             = 0x0,
  UnregisterClientIndex,
  AddDevicePreDeviceCreateIndex,
  AddDevicePostDeviceCreateIndex,
  HwNExportLastExportIndex
} HWN_CLX_EXPORT_INDEX;
```

## See also

[Hardware notifications support](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/hardware-notifications-support)

[Hardware notifications reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_gpio)