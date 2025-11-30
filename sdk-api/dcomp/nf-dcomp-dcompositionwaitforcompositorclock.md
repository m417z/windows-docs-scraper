## Description

Halts a thread until the next signal from the compositor clock occurs.

## Parameters

### `count`

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The number of _`handles`_.

### `handles`

Type: **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Handles to events for which the compositor clock should send signals.

### `timeoutInMs`

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Amount of time in milliseconds to wait before the operation times out.

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Returns a status code (an **NTSTATUS** value) that indicates the success or failure of the function. If the method succeeds, then it will return `STATUS_SUCCESS`. If the display is off, then the function returns immediately with **STATUS_GRAPHICS_PRESENT_OCCLUDED**. For other **NTSTATUS** values, see [NTSTATUS values](https://learn.microsoft.com/openspecs/windows_protocols/ms-erref/596a1078-e883-4972-9bbc-49e60bebca55).

## Remarks

## See also

[DCompositionGetTargetStatistics](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/dcomp/nf-dcomp-dcompositiongettargetstatistics.md), [DCompositionGetStatistics](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositiongetstatistics), [DCompositionGetFrameId](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositiongetframeid), [DCompositionBoostCompositorClock](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositionboostcompositorclock)