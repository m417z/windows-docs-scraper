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

## Remarks

## See also

[DCompositionGetTargetStatistics](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/dcomp/nf-dcomp-dcompositiongettargetstatistics.md), [DCompositionGetStatistics](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositiongetstatistics), [DCompositionGetFrameId](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositiongetframeid), [DCompositionBoostCompositorClock](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositionboostcompositorclock)