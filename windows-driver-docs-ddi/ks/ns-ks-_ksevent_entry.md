# _KSEVENT_ENTRY structure

## Description

The kernel streaming subsystem uses the KSEVENT_ENTRY structure to describe how an event should be triggered.

## Members

### `ListEntry`

### `Object`

### `DpcItem`

### `BufferItem`

### `EventData`

### `NotificationType`

### `EventSet`

### `EventItem`

### `FileObject`

### `SemaphoreAdjustment`

### `Reserved`

### `Flags`

## Remarks

Drivers that do not provide an [AVStrMiniRemoveEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksremoveevent) handler should treat this as an opaque data structure.

For more information, see [Event Handling in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/event-handling-in-avstream).