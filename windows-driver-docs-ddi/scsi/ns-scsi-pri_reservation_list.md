## Description

The **PRI_RESERVATION_LIST** structure is returned in response to a Persistent Reserve In command with ServiceAction = RESERVATION_ACTION_READ_RESERVATIONS.

## Members

### `Generation`

The Generation field contains a 32-bit counter that is maintained by the device server, which is incremented every time a Persistent Reserve Out command requests a REGISTER, REGISTER AND IGNORE EXISTING KEY, CLEAR, PREEMPT, or PREEMPT AND ABORT service action.

### `AdditionalLength`

The AdditionalLength field contains a count of the number of bytes in the reservation descriptors.

### `Reservations`

An array of reservation descriptors.

## Remarks

The [**IOCTL_STORAGE_PERSISTENT_RESERVE_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_persistent_reserve_in) request is used to obtain information about persistent reservations and reservation keys that are active within a device server.

## See also

[**IOCTL_STORAGE_PERSISTENT_RESERVE_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_persistent_reserve_in)