# PHDAUDIO_DMA_NOTIFICATION_CALLBACK callback function

## Description

HDAudio codec DMA Notification Callback function.

**PHDAUDIO_DMA_NOTIFICATION_CALLBACK** is used by the [PREGISTER_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_notification_callback) callback function.

## Parameters

### `unnamedParam1`

**Context** - Driver-specific context value used when registering the callback routine.

### `unnamedParam2`

**QPCDMANotificationTimestamp** - The QPC time when the IOC ISR handled the DMA interrupt.

## Prototype

```cpp
//Declaration

PHDAUDIO_DMA_NOTIFICATION_CALLBACK PHdAudioDmaNotificationCallback;

// Definition

VOID PHdAudioDmaNotificationCallback
(
	PVOID Context
	LARGE_INTEGER QPCDMANotificationTimestamp
)
{...}
```

## Remarks

## See also

[hdaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/)