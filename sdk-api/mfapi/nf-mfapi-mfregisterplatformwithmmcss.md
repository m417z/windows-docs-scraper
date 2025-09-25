# MFRegisterPlatformWithMMCSS function

## Description

Registers the standard Microsoft Media Foundation platform work queues with the Multimedia Class Scheduler Service (MMCSS).

## Parameters

### `wszClass` [in]

The name of the MMCSS task.

### `pdwTaskId` [in, out]

The MMCSS task identifier. On input, specify an existing MCCSS task group ID, or use the value zero to create a new task group. On output, receives the actual task group ID.

### `lPriority` [in]

The base priority of the work-queue threads.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To unregister the platform work queues from the MMCSS class, call [MFUnregisterPlatformFromMMCSS](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfunregisterplatformfrommmcss).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queue and Threading Improvements](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-work-queue-and-threading-improvements)