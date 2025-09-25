# _D3DKMT_OPENKEYEDMUTEXFROMNTHANDLE structure

## Description

Contains information to open a keyed mutex from an NT handle to the process.

## Members

### `hNtHandle`

Handle to the process.

### `hKeyedMutex`

A handle to the keyed mutex in this process.

### `pPrivateRuntimeData`

A buffer that contains initial private data.

### `PrivateRuntimeDataSize`

The size, in bytes, of the buffer pointed to by the pPrivateRuntimeData member.