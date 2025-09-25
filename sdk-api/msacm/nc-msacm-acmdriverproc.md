# ACMDRIVERPROC callback function

## Description

The **acmDriverProc** function specifies a callback function used with the ACM driver. The **acmDriverProc** name is a placeholder for an application-defined function name. The actual name must be exported by including it in the module-definition file of the executable or DLL file.

## Parameters

### `unnamedParam1`

Identifier of the installable ACM driver.

### `unnamedParam2`

Handle to the installable ACM driver. This parameter is a unique handle the ACM assigns to the driver.

### `unnamedParam3`

ACM driver message.

### `unnamedParam4`

Message parameter.

### `unnamedParam5`

Message parameter.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

Applications should not call any system-defined functions from inside a callback function, except for **PostMessage**, [timeGetSystemTime](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timegetsystemtime), [timeGetTime](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timegettime), [timeSetEvent](https://learn.microsoft.com/previous-versions/dd757634(v=vs.85)), [timeKillEvent](https://learn.microsoft.com/previous-versions/dd757630(v=vs.85)), [midiOutShortMsg](https://learn.microsoft.com/previous-versions/dd798481(v=vs.85)), [midiOutLongMsg](https://learn.microsoft.com/previous-versions/dd798474(v=vs.85)), and **OutputDebugStr**.

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)