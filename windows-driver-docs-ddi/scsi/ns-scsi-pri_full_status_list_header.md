## Description

The **PRI_FULL_STATUS_LIST_HEADER** structure is the first member of a **[PRI_FULL_STATUS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-pri_full_status_list)** that is returned in response to a Persistent Reserve In command with `ServiceAction=RESERVATION_ACTION_READ_FULL_STATUS`.

## Members

### `Generation[4]`

The Generation field contains a 32-bit counter that is maintained by the device server, which is incremented every time a Persistent Reserve In command requests a RESERVATION_ACTION_READ_FULL_STATUS service action.

### `AdditionalLength[4]`

The *AdditionalDescriptorLength* field indicates the number of bytes that follow.

## Remarks

## See also

- **[PRI_FULL_STATUS_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-pri_full_status_list)**