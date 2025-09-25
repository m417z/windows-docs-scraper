## Description

Specifies the level of an APO event logged with [IAudioProcessingObjectLoggingService::ApoLog](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/nf-audioengineextensionapo-iaudioprocessingobjectloggingservice-apolog).

## Constants

### `APO_LOG_LEVEL_ALWAYS:0`

All events.

### `APO_LOG_LEVEL_CRITICAL:1`

Abnormal exit or termination events.

### `APO_LOG_LEVEL_ERROR:2`

Severe error events.

### `APO_LOG_LEVEL_WARNING:3`

Warning events such as allocation failures.

### `APO_LOG_LEVEL_INFO:4`

Non-error events such as entry or exit events.

### `APO_LOG_LEVEL_VERBOSE:5`

Detailed trace events.

## Remarks

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also