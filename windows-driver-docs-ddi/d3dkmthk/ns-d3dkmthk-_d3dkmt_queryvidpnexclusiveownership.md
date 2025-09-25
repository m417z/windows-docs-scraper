# _D3DKMT_QUERYVIDPNEXCLUSIVEOWNERSHIP structure

## Description

Used to query for VidPn exclusive ownership.

## Members

### `hProcess` [in]

A handle to the process.

### `hWindow` [in]

A handle to the window.

### `VidPnSourceId` [out]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the monitor is connected to.

### `AdapterLuid` [out]

The adapter LUID (locally unique identifier).

### `OwnerType` [out]

The owner type.

## Remarks

## See also