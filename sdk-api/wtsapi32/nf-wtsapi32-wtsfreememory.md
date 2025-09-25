# WTSFreeMemory function

## Description

Frees memory allocated by a Remote Desktop Services function.

## Parameters

### `pMemory` [in]

Pointer to the memory to free.

## Remarks

Several Remote Desktop Services functions allocate buffers to return information. Use the
**WTSFreeMemory** function to free these buffers.

## See also

[WTSEnumerateProcesses](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumerateprocessesa)

[WTSEnumerateSessions](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa)

[WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa)

[WTSQueryUserConfig](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsqueryuserconfiga)