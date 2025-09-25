# _D3DKMT_SUBMITWAITFORSYNCOBJECTSTOHWQUEUE structure

## Description

A structure that contains information to submit a wait on the hardware queue.

## Members

### `hHwQueue`

Context queue to submit the command to.

### `ObjectCount`

Number of objects to wait on.

### `ObjectHandleArray`

Handles to monitored fence synchronization objects to wait on.

### `FenceValueArray`

Monitored fence values to be waited.