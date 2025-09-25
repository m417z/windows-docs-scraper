## Description

The **PRI_REGISTRATION_LIST** structure is returned in response to a Persistent Reserve In command with ServiceAction = RESERVATION_ACTION_READ_KEYS.

## Members

### `Generation[4]`

The Generation field contains a 32-bit counter that is maintained by the device server, which is incremented every time a Persistent Reserve Out command requests a REGISTER, REGISTER AND IGNORE EXISTING KEY, CLEAR, PREEMPT, or PREEMPT AND ABORT service action.

### `AdditionalLength[4]`

The AdditionalLength field contains a count of the number of bytes in the reservation key list.

### `ReservationKeyList[0]`

The reservation key list contains the 8-byte reservation keys for all initiators that have registered by using all ports with the device server.

## Remarks

The [**IOCTL_STORAGE_PERSISTENT_RESERVE_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_persistent_reserve_in) request is used to obtain information about persistent reservations and reservation keys that are active within a device server.

## See also

[**IOCTL_STORAGE_PERSISTENT_RESERVE_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_persistent_reserve_in)