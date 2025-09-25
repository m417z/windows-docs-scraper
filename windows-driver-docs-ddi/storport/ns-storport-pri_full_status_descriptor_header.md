## Description

The **PRI_FULL_STATUS_DESCRIPTOR_HEADER** structure is the first member of a **[PRI_FULL_STATUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-pri_full_status_descriptor)** structure, which is used to populate a **[PRI_FULL_STATUS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-pri_full_status_list)**.

## Members

### `ReservationKey[8]`

The reservation key under which the persistent reservation is held.

### `Reserved[4]`

Reserved for internal use.

### `ReservationHolder`

A reservation holder set to one indicates that all initiator and target ports described by this full status descriptor are registered and are persistent reservation holders. A reservation holder set to zero indicates that all initiator and target ports described by this full status descriptor are registered but are not persistent reservation holders.

### `AllTargetPorts`

An *AllTargetPorts* value of zero indicates that this full status descriptor represents a single initiator port and target port pair. An *AllTargetPorts* value of one indicates:

- This full status descriptor represents all the initiator and target ports that are associated with both:
  - The initiator port (I) is specified by the *TransportID*
  - Every target port (T) is in the target device
- All the initiator and target ports are registered with the same reservation key
- All the initiator and target ports are either reservation holders or not reservation holders as indicated by the *ReservationHolder* field

### `Reserved1`

Reserved for internal use.

### `Type`

If *ReservationHolder* is set to one, the *Type* field is defined in the Persistent Reserve In command with `ServiceAction=RESERVATION_ACTION_READ_KEYS`. If *ReservationHolder* is set to zero, the contents of the *Type* field is not defined by this standard.

### `Scope`

If *ReservationHolder* is set to one, the *Scope* field is defined in the Persistent Reserve In command with `ServiceAction=RESERVATION_ACTION_READ_KEYS`. If *ReservationHolder* is set to zero, the contents of the *Scope* field is not defined by this standard.

### `Reserved2[4]`

Reserved for internal use.

### `RelativeTargetPortIdentifier[2]`

Identifies the target port relative to the initiator port.

### `AdditionalDescriptorLength[4]`

The *AdditionalDescriptorLength* field indicates the number of bytes that follow.

## Remarks

## See also

- **[PRI_FULL_STATUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-pri_full_status_descriptor)**