# TraceLoggingRegisterEx function

## Description

Registers a TraceLogging provider so that it can be used to log events,
specifying an ETW enable callback. The registration is valid until the provider
is unregistered or the process exits.

## Parameters

### `hProvider` [in, out]

The handle of the TraceLogging provider to register. The handle must not already
be registered.

### `pEnableCallback` [in, optional]

[ETW Enable Callback](https://learn.microsoft.com/windows/win32/api/evntprov/nc-evntprov-penablecallback) that will be
invoked when a trace session enables or disables your provider.

### `pCallbackContext` [in, optional]

Optional provider-defined context pointer to pass to the callback.

## Return value

If you call this function from user-mode code, the function returns an
`HRESULT`. Use the `SUCCEEDED()` macro to determine whether the function
succeeds.

If you call this function from kernel-mode code, the function returns an
`NTSTATUS`. Use the `NT_SUCCESS()` macro to determine whether the function
succeeds.

> [!NOTE]
> The error code returned by TraceLoggingRegisterEx is primarily
> intended for use in debugging and diagnostic scenarios. Most production code
> should continue to run even if an ETW provider failed to register, so release
> builds should usually ignore the error code returned by
> TraceLoggingRegisterEx.

## Remarks

See [TraceLoggingRegister](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingregister)
for details on registering providers. See
[ETW Enable Callback](https://learn.microsoft.com/windows/win32/api/evntprov/nc-evntprov-penablecallback) for details on
the callback behavior.

**TraceLoggingRegisterEx** does the following:

- Calls **EventRegister** to open the connection to ETW.
- If **EventRegister** succeeds, calls
[TraceLoggingSetInformation](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingsetinformation)
with _InformationClass_
[EventProviderSetTraits](https://learn.microsoft.com/windows/win32/api/evntprov/ne-evntprov-event_info_class) to
configure the provider for TraceLogging support.

A call to
[**TraceLoggingRegister**](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingregister) is
the same as a call to **TraceLoggingRegisterEx** with NULL for the _callback_
and _context_ parameters. Use **TraceLoggingRegisterEx** if you need to receive
an ETW Enable Callback when sessions enable or disable your provider.

## See also

[ETW Enable Callback](https://learn.microsoft.com/windows/win32/api/evntprov/nc-evntprov-penablecallback)

[EventRegister](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventregister)

[TraceLoggingRegister](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingregister)

[TraceLoggingUnregister](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingunregister)

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TRACELOGGING_DEFINE_PROVIDER](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-tracelogging_define_provider)