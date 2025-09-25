# _D3DKMT_CREATEHWCONTEXT structure

## Description

A structure holding information to create a hardware context.

## Members

### `hDevice`

Handle to the device owning this context.

### `NodeOrdinal`

Identifier for the node targeted by this context.

### `EngineAffinity`

Engine affinity within the specified node.

### `Flags`

Context creation flags.

### `PrivateDriverDataSize`

Size of private driver data.

### `pPrivateDriverData`

Private driver data.

### `hHwContext`

Handle of the created context.