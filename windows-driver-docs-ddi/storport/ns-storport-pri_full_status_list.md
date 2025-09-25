## Description

The **PRI_FULL_STATUS_LIST** structure is returned in response to a Persistent Reserve In command with `ServiceAction=RESERVATION_ACTION_READ_FULL_STATUS`.

## Members

### `Generation[4]`

The Generation field contains a 32-bit counter that is maintained by the device server, which is incremented every time a Persistent Reserve In command requests a RESERVATION_ACTION_READ_FULL_STATUS service action.

### `AdditionalLength[4]`

The *AdditionalDescriptorLength* field indicates the number of bytes in the full status list.

### `FullStatusDescriptors[ANYSIZE_ARRAY]`

An array of **[PRI_FULL_STATUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-pri_full_status_descriptor)** structures.

## Remarks

## See also

- **[PRI_FULL_STATUS_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-pri_full_status_descriptor)**
- **[PRI_FULL_STATUS_DESCRIPTOR_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-pri_full_status_descriptor_header)**