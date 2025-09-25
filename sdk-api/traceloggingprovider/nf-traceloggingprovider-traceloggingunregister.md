## Description

Unregisters a TraceLogging provider.

## Parameters

### `hProvider`

The handle of the TraceLogging provider to unregister.

## Remarks

When a component starts running, any TraceLogging provider handle in the
component will be in an unregistered state and any attempts to use the
provider's handle to generate events will be silently ignored. Before the
provider can write any events, you need to register the provider using
[**TraceLoggingRegister**](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingregister).
You will typically do this during component startup. At component shutdown,
unregister the provider by calling **TraceLoggingUnregister**, e.g. before
returning from `main`, `wmain`, or `WinMain`, in `DllMain(DLL_PROCESS_DETACH)`,
before returning from a failed `DriverEntry`, or in the driver Unload routine.

**TraceLoggingRegister** is not thread-safe with regards to other calls to
**TraceLoggingRegister** or **TraceLoggingUnregister** on the same handle. Do
not call **TraceLoggingRegister** if it is possible that another thread might
call **TraceLoggingRegister** or **TraceLoggingUnregister** on the same handle
at the same time.

If **TraceLoggingRegister** fails, the provider handle will remain unregistered
and all uses of the provider handle will be safe no-ops. In particular, it is a
safe no-op to call **TraceLoggingWrite** or **TraceLoggingUnregister** with an
unregistered provider handle.

> [!IMPORTANT]
> If your DLL or driver calls `TraceLoggingRegister` on a provider
> handle, it **must** call `TraceLoggingUnregister` on that provider handle
> before the DLL or driver unloads. If a DLL unloads without calling
> `TraceLoggingUnregister`, the process may subsequently crash. If a driver
> unloads without calling `TraceLoggingUnregister`, the system may subsequently
> crash. The `TraceLoggingRegister` function establishes an ETW configuration
> callback, and `TraceLoggingUnregister` cancels the callback. If the callback
> is not cancelled and the module unloads, a crash will occur the next time ETW
> tries to invoke the callback.

## See also

[TraceLoggingRegister](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingregister)

[EventUnregister](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventunregister)