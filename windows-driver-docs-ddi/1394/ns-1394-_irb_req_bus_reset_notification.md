# _IRB_REQ_BUS_RESET_NOTIFICATION structure

## Description

This structure contains the fields necessary for the 1394 bus driver to carry out a bus reset notification request.

This is the suggested method for a client driver on top of the 1394 bus driver to get notified about 1394 bus resets. The client registers by using this IRB in its START_DEVICE routine, and de-registers using the same IRB, but with different flags, in its REMOVE routine.

This notification is only issued if after the bus reset, the target device is still present on the bus. This way the caller does not have to verify that the target device is on the bus.

## Members

### `fulFlags`

Specifies whether a callback should be registered or deactivated. Use REGISTER_NOTIFICATION_ROUTINE to register **ResetRoutine** as the callback. Use DEREGISTER_NOTIFICATION_ROUTINE to deactivate any previously registered callback.

**Note** In Windows 7 and later, set the EXTENDED_NOTIFICATION_ROUTINE flag to register for extended bus reset notifications supported by the new IEEE 1394 bus driver. This notification returns information about the current generation of the bus, such as the generation count and node ids, to 1394 client drivers in the context of the bus reset notification.

### `ResetRoutine`

Points to the notification routine for bus resets. The notification routine parameters follow this prototype:

```
void BusResetNotificationRoutine(IN PVOID Context);

```

### `ResetContext`

Specifies the argument to be passed to the notification routine.

When the EXTENDED_NOTIFICATION_ROUTINE flag is specified, **ResetContext** points to a [BUS_RESET_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_bus_reset_data) structure.