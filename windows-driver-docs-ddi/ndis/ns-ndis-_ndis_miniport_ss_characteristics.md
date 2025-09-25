# _NDIS_MINIPORT_SS_CHARACTERISTICS structure

## Description

The **NDIS_MINIPORT_SS_CHARACTERISTICS** structure specifies the pointers to a miniport driver's NDIS selective suspend handler functions. These functions are called by NDIS to issue idle notifications to the driver during a selective suspend operation.

## Members

### `Header`

The type, revision, and size of the **NDIS_MINIPORT_SS_CHARACTERISTICS** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_MINIPORT_SS_CHARACTERISTICS. To specify the version of the **NDIS_MINIPORT_SS_CHARACTERISTICS** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_MINIPORT_SS_CHARACTERISTICS_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_MINIPORT_SS_CHARACTERISTICS_REVISION_1.

### `Flags`

 A **ULONG** value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `IdleNotificationHandler`

A pointer to the miniport driver's [MiniportIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_idle_notification) function.

### `CancelIdleNotificationHandler`

A pointer to the miniport driver's [MiniportCancelIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_idle_notification) function.

## Remarks

To register the handler functions for NDIS selective suspend, the miniport driver follows these steps when its [MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function is called:

1. The miniport driver initializes an **NDIS_MINIPORT_SS_CHARACTERISTICS** structure with pointers to the handler functions.
2. The miniport driver then calls [NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) and sets the *OptionalHandlers* parameter to a pointer to the **NDIS_MINIPORT_SS_CHARACTERISTICS** structure.

For more information on how to handle idle notifications for NDIS selective suspend, see [NDIS Selective Suspend Idle Notifications](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-selective-suspend-idle-notifications).

## See also

[MiniportCancelIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_idle_notification)

[MiniportIdleNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_idle_notification)

[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)