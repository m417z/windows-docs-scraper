# _D3DKMT_CREATE_OUTPUTDUPL structure

## Description

Reserved for system use. Do not use in your driver.

## Members

### `hAdapter`

A handle to the display adapter.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the display mode applies to.

### `KeyedMutexCount` [in]

The number of keyed mutexs. If zero, then this the pre-create check.

### `RequiredKeyedMutexCount` [out]

The number of keyed mutexs needed.

### `KeyedMutexs`

Pointer to an array of keyed mutexs.

### `Flags`

Flags required to create the structure.

## Remarks

## See also