## Description

The **PRO_PARAMETER_LIST** structure is sent in a Persistent Reserve Out command to a device server.

## Members

### `ReservationKey[8]`

The ReservationKey field contains an 8-byte value that is provided by the application client to the device server. This value identifies the initiator that is the source of the Persistent Reserve Out command.

### `ServiceActionReservationKey[8]`

The ServiceActionReservationKey field contains information that is needed for the following four service actions:

- REGISTER

- REGISTER AND IGNORE EXISTING KEY

- PREEMPT

- PREEMPT AND ABORT

### `ScopeSpecificAddress[4]`

The ScopeSpecificAddress field contains the element address that has zeros placed in the most significant bits to fit the field. This is true if the scope of a reservation is set to ELEMENT_SCOPE. Otherwise, this field is set to all zeros.

### `ActivatePersistThroughPowerLoss`

The ActivatePersistThroughPowerLoss (APTPL) bit is valid only for the following service actions:

- REGISTER

- REGISTER AND IGNORE EXISTING KEY

### `Reserved1`

Reserved. Must be zero.

### `AllTargetPorts`

Defines the **UCHAR** member **AllTargetPorts**.

### `SpecifyInitiatorPorts`

Defines the **UCHAR** member **SpecifyInitiatorPorts**.

### `Reserved2`

Reserved. Must be zero.

### `Reserved3`

Reserved. Must be zero.

### `Obsolete[2]`

Reserved. Must be zero.

## Remarks

The [**IOCTL_STORAGE_PERSISTENT_RESERVE_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_persistent_reserve_out) request is used to control information about persistent reservations and reservation keys that are active within a device server.

## See also

[**IOCTL_STORAGE_PERSISTENT_RESERVE_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_persistent_reserve_out)