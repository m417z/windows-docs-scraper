# _WDF_CALLBACK_CONSTRAINT enumeration

## Description

## Constants

### `None`

No callback functions into the driver are synchronized. The driver must handle all synchronization.

### `WdfDeviceLevel`

All callback functions into the driver that are associated with the device are synchronized, including all callback functions that are associated with I/O queues. Only one event handler that is associated with the device can run at any given time.

### `WdfLevelReserved`

Reserved.

### `WdfLevelMaximum`

## Remarks

Note that the above locking models apply only for I/O (that is, open, read, write, and device I/O control) operations and not for Plug and Play (PnP) and power management notifications.