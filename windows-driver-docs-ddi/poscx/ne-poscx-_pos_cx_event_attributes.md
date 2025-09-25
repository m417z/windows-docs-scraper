## Description

The POS_CX_EVENT_ATTRIBUTES enumeration describes the priority and access rights for the POS events coming from the device. The values are a combination of the values defined in [POS_CX_EVENT_DEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/ne-poscx-_pos_cx_event_dest) and [POS_CX_EVENT_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/ne-poscx-_pos_cx_event_priority).

## Constants

### `POS_CX_EVENT_ATTR_DATA`

Data level priority delivered in FIFO to the claim owner handle.

### `POS_CX_EVENT_ATTR_CONTROL`

Control level priority delivered in FIFO to the claim owner handle.

### `POS_CX_EVENT_ATTR_BCAST_CONTROL`

Control level priority delivered in FIFO to ALL open handles on the driver.

## Remarks

PosCx will deliver all Control level events before Data level events.

## See also

[POS_CX_EVENT_DEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/ne-poscx-_pos_cx_event_dest)

[POS_CX_EVENT_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/ne-poscx-_pos_cx_event_priority)