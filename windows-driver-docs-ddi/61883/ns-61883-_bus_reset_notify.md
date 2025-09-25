# _BUS_RESET_NOTIFY structure

## Description

This structure is used to register or deregister the [PBUS_RESET_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/nc-61883-pbus_reset_routine) callback. The request registers the caller to be notified when a reset of the 1394 bus occurs or cancels a previous registration. When the registered callback (bus reset) routine is called, the updated generation count and node address will be specified in parameter **BusResetInfo**. If a driver registers for bus-reset notification, it must cancel registration before the system unloads the driver.

## Members

### `Flags`

The caller sets this member to REGISTER_BUS_RESET_NOTIFY to register to receive bus-reset notifications, or to DEREGISTER_BUS_RESET_NOTIFY to stop receiving bus-reset notifications.

### `pfnNotify`

Pointer to a caller-supplied function to be called by the protocol driver when the 1394 bus is reset.

This function uses the following prototype:

```
Void
  (*PBUS_RESET_ROUTINE)(
 IN PVOID  Context;
 IN PBUS_GENERATION_NODE  BusResetInfo;
 );
```

### `Context`

Pointer to a caller-defined context for the function at **pfnNotify**. The IEC-61883 protocol driver calls this function after a reset of the 1394 bus.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

If an incorrect parameter is passed in, the protocol driver sets **Irp->IoStatus.Status** to STATUS_INVALID_PARAMETER.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)