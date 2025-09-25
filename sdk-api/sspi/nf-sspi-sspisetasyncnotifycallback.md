# SspiSetAsyncNotifyCallback function

## Description

Registers a callback that is notified on async call completion.

## Parameters

### `Context`

The async call context.

### `Callback`

The SspiAsyncNotifyCallback that will be notified on call completion.

### `CallbackData`

An opaque pointer that is passed to [SspiAsyncNotifyCallback](https://learn.microsoft.com/windows/win32/api/sspi/nc-sspi-sspiasyncnotifycallback).

## Return value

## Remarks

The *Callback* and *CallbackData* parameters can be set to **null** in order to specify that the caller is not interested in the result of the operation.

> [!NOTE]
> Setting the callback to null is only supported for [SspiDeleteSecurityContextAsync](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspideletesecuritycontextasync)

## See also

[SspiAsyncNotifyCallback](https://learn.microsoft.com/windows/win32/api/sspi/nc-sspi-sspiasyncnotifycallback)