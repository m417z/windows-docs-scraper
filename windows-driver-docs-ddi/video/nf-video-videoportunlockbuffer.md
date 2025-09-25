# VideoPortUnlockBuffer function

## Description

The **VideoPortUnLockBuffer** function unlocks physical pages described by the specified memory descriptor list ([MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)).

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `Mdl` [in]

Pointer to the MDL of the buffer to be released. This parameter should be the same pointer that was returned by [VideoPortLockBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportlockbuffer).

## Return value

None

## See also

[VideoPortLockBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportlockbuffer)