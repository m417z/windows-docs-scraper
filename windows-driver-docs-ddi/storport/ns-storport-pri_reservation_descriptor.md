## Description

The PRI_RESERVATION_DESCRIPTOR structure is used to construct the [**PRI_RESERVATION_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-pri_reservation_list) structure that is returned in response to a Persistent Reserve In command with ServiceAction = RESERVATION_ACTION_READ_RESERVATIONS.

## Members

### `ReservationKey`

The reservation key under which the persistent reservation is held.

### `ScopeSpecificAddress`

The ScopeSpecificAddress field contains the element address, that has zeros placed in the most significant bits to fit the field.

### `Reserved`

Reserved. Must be zero.

### `Type`

The type of the persistent reservation as present in the Persistent Reserve Out command that created the persistent reservation.

### `Scope`

The scope of the persistent reservation as present in the Persistent Reserve Out command that created the persistent reservation.

### `Obsolete`

Reserved. Must be zero.

## Remarks

The [IOCTL_STORAGE_PERSISTENT_RESERVE_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_persistent_reserve_in) request is used to obtain information about persistent reservations and reservation keys that are active within a device server.

## See also

[IOCTL_STORAGE_PERSISTENT_RESERVE_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_persistent_reserve_in)

[**PRI_RESERVATION_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-pri_reservation_list)