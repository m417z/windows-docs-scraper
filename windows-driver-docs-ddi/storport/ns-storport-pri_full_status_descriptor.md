## Description

The **PRI_FULL_STATUS_DESCRIPTOR** structure is used to construct the **[PRI_FULL_STATUS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-pri_full_status_list)** structure that is returned in response to a Persistent Reserve In command with `ServiceAction=RESERVATION_ACTION_READ_FULL_STATUS`.

## Members

### `Header`

Contains the **[PRI_FULL_STATUS_DESCRIPTOR_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-pri_full_status_descriptor_header)** structure.

### `TransportID[ANYSIZE_ARRAY]`

The *TransportID* identifies the initiator port that is described by this full status descriptor.

## Remarks

The **[IOCTL_STORAGE_PERSISTENT_RESERVE_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_persistent_reserve_in)** request is used to obtain information about persistent reservations and reservation keys that are active within a device server.

## See also

- **[IOCTL_STORAGE_PERSISTENT_RESERVE_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_persistent_reserve_in)**
- **[PRI_FULL_STATUS_DESCRIPTOR_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-pri_full_status_descriptor_header)**