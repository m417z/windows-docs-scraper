# _D3DDDICB_SUBMITWAITFORSYNCOBJECTSTOHWQUEUE structure

## Description

A structure that holds information to wait for synchronized objects.

## Members

### `hHwQueue`

Hardware queue to queue the wait on.

### `ObjectCount`

Number of objects to wait on.

### `ObjectHandleArray`

Handles to monitored fence synchronization objects to wait on.

### `FenceValueArray`

Monitored fence values to be waited on.