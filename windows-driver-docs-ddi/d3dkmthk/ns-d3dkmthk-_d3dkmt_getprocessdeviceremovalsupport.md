# _D3DKMT_GETPROCESSDEVICEREMOVALSUPPORT structure

## Description

Used to get process device removal support.

## Members

### `hProcess`

Handle to the process.

### `AdapterLuid`

Luid of Adapter that is potentially being detached.

### `Support`

Determines whether or not the process using the adapter can recover from graphics device removal.