## Description

Logs an APO event.

## Parameters

### `level`

A value from the [APO_LOG_LEVEL](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ne-audioengineextensionapo-apo_log_level) enumeration specifying the level of the event being logged.

### `format`

The format-control string for the log message.

### `...`

Format argument list.

## Remarks

> [!NOTE]
> This method should never be called from a real-time priority thread. For more information on thread priorities, see [Scheduling Priorities](https://learn.microsoft.com/windows/win32/procthread/scheduling-priorities).

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also