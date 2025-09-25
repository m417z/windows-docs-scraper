# VideoPortReadStateEvent function

## Description

The **VideoPortReadStateEvent** function returns the current state of a given event object: signaled or nonsignaled.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `pEvent` [in]

Pointer to the event object whose state is to be read.

## Return value

**VideoPortReadStateEvent** returns a nonzero value if the event object is currently in the signaled state. If the event object is in the nonsignaled state, this function returns zero.

## Remarks

This function is available in Windows XP and later.