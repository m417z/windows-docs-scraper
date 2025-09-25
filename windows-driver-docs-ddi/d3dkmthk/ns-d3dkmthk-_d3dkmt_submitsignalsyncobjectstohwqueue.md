# _D3DKMT_SUBMITSIGNALSYNCOBJECTSTOHWQUEUE structure

## Description

A structure holding information to submit a signal to the hardware queue.

## Members

### `Flags`

Flags that specify signal behavior.

### `BroadcastHwQueueCount`

Specifies the number of hardware queues to broadcast this signal to.

### `BroadcastHwQueueArray`

Specifies hardware queue handles to broadcast to.

### `ObjectCount`

Number of objects to signal.

### `ObjectHandleArray`

Handles to monitored fence synchronization objects to signal.

### `FenceValueArray`

Monitored fence values to signal.