# _D3DDDICB_SUBMITSIGNALSYNCOBJECTSTOHWQUEUE structure

## Description

A structure that holds information to submit a signal synchronization object to a hardware queue.

## Members

### `Flags`

Specifies signal behavior.

### `BroadcastHwQueueCount`

Specifies the number of hardware queues to broadcast this signal to.

### `BroadcastHwQueueArray`

Specifies hardware queue handles to broadcast to.

### `ObjectCount`

Number of objects to signal.

### `ObjectHandleArray`

Handles to monitored fence synchronization objects to signal.

### `FenceValueArray`

monitored fence values to signal.