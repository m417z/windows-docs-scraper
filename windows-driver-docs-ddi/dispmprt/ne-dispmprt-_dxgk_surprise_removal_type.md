# _DXGK_SURPRISE_REMOVAL_TYPE enumeration

## Description

Indicates the type of surprise removal event when an external display device is disconnected from the system.

## Constants

### `DxgkRemovalHibernation`

The disconnected external display device was in hibernation mode.

### `DxgkRemovalPnPNotify`

The disconnected external display device was surprise removed/unplugged while it was still running.

## Remarks

See the [**DXGKDDI_NOTIFY_SURPRISE_REMOVAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_notify_surprise_removal) callback for details.