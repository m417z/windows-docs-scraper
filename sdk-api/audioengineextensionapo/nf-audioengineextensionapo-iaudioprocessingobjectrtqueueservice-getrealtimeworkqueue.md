## Description

Gets the ID of a work queue that the APO can use to schedule tasks that need to run at a real-time priority.

## Parameters

### `workQueueId`

A DWORD containing the work queue ID.

## Return value

Returns S_OK on success.

## Remarks

The returned work queue ID is used with the real-time work queue APIs. For more information see [rtworkq.h header](https://learn.microsoft.com/windows/win32/api/rtworkq/).

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also