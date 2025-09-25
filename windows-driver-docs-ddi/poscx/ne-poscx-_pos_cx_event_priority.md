## Description

The POS_CX_EVENT_PRIORITY defines the importance of the event and the order it will be delivered to the client application.

## Constants

### `POS_CX_EVENT_PRIORITY_INVALID`

Invalid priority. This value should not be used.

### `POS_CX_EVENT_PRIORITY_DATA`

Data level priority delivered in FIFO.

### `POS_CX_EVENT_PRIORITY_CONTROL`

Control level priority delivered in FIFO.

### `POS_CX_EVENT_PRIORITY__MAX`

## Remarks

PosCx will deliver all Control level events before Data level events.