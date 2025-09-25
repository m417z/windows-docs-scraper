# FWPS_VSWITCH_EVENT_TYPE_ enumeration

## Description

The FWPS_VSWITCH_EVENT_TYPE enumeration type specifies the type of a virtual switch event notification.

## Constants

### `FWPS_VSWITCH_EVENT_VSWITCH_NONE`

Indicates no specific virtual switch event.

### `FWPS_VSWITCH_EVENT_VSWITCH_CREATE`

Indicates that the virtual switch instance was created.

### `FWPS_VSWITCH_EVENT_VSWITCH_DELETE`

Indicates that the virtual switch instance was deleted.

### `FWPS_VSWITCH_EVENT_PORT_CREATE`

Indicates that the virtual switch port was created.

### `FWPS_VSWITCH_EVENT_PORT_DELETE`

Indicates that the virtual switch port was deleted.

### `FWPS_VSWITCH_EVENT_INTERFACE_CREATE`

Indicates that the virtual switch interface was created.

### `FWPS_VSWITCH_EVENT_INTERFACE_DELETE`

Indicates that the virtual switch interface was deleted.

### `FWPS_VSWITCH_EVENT_INTERFACE_CONNECT`

Indicates that the virtual switch interface was connected.

### `FWPS_VSWITCH_EVENT_INTERFACE_DISCONNECT`

Indicates that the virtual switch interface was disconnected.

### `FWPS_VSWITCH_EVENT_POLICY_ADD`

Indicates the addition of a policy for a virtual switch port.

### `FWPS_VSWITCH_EVENT_POLICY_UPDATE`

Indicates a policy update to a virtual switch port.

### `FWPS_VSWITCH_EVENT_POLICY_DELETE`

Indicates the deletion of a policy for a virtual switch port.

### `FWPS_VSWITCH_EVENT_RUNTIME_STATE_SAVE`

Indicates a virtual switch run-time state save event.

### `FWPS_VSWITCH_EVENT_RUNTIME_STATE_RESTORE`

Indicates a virtual switch run-time state restore event.

## Remarks

The
FWPS_VSWITCH_EVENT_TYPE enumeration defines the values for the *eventType* parameter of the virtual switch notification functions that are included in the [FWPS_VSWITCH_EVENT_DISPATCH_TABLE0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_vswitch_event_dispatch_table0_) structure.

## See also

[FWPS_VSWITCH_EVENT_DISPATCH_TABLE0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_vswitch_event_dispatch_table0_)