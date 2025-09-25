# WinBioCloseFramework function

## Description

Closes a framework handle previously opened with [WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework). Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `FrameworkHandle` [in]

Handle to the framework session that will be closed.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error.

## Remarks

This function never blocks.