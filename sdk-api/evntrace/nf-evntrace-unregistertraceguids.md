# UnregisterTraceGuids function

## Description

The **UnregisterTraceGuids** function unregisters a
[Classic](https://learn.microsoft.com/windows/win32/etw/tracing-events) (Windows 2000-style) ETW event
trace provider that was registered using
[RegisterTraceGuids](https://learn.microsoft.com/windows/desktop/ETW/registertraceguids).

## Parameters

### `RegistrationHandle` [in]

Handle to the event trace provider, obtained from an earlier call to the
[RegisterTraceGuids](https://learn.microsoft.com/windows/desktop/ETW/registertraceguids) function.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the
[system error codes](https://learn.microsoft.com/windows/win32/debug/system-error-codes). The following
are some common errors and their causes.

- **ERROR_INVALID_PARAMETER**

 The _RegistrationHandle_ parameter does not specify the handle to a registered
provider or is **NULL**.

## Remarks

Providers call this function.

The event trace provider must have been registered previously by calling the
[RegisterTraceGuids](https://learn.microsoft.com/windows/desktop/ETW/registertraceguids) function.

> [!Important]
> All registration handles created by a DLL or driver must be
> unregistered before the DLL or driver unloads. If the provider is not
> unregistered, a crash will occur when ETW tries to invoke the provider's
> callback.

## See also

[RegisterTraceGuids](https://learn.microsoft.com/windows/desktop/ETW/registertraceguids)