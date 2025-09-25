# TRACELOGGING_DECLARE_PROVIDER macro

## Description

Forward-declares a handle for a TraceLogging provider.

## Parameters

### `handleVariable` [in]

The handle name to forward-declare. This should be the name of a handle that has
been defined in a .c or .cpp file using
[TRACELOGGING_DEFINE_PROVIDER](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-tracelogging_define_provider).

## Remarks

Use this macro as needed to forward-declare your TraceLogging provider handle,
e.g. in a header file of your component. This macro does not allocate storage
for the provider handle. In order to use the provider, you will need to use
[TRACELOGGING_DEFINE_PROVIDER](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-tracelogging_define_provider)
to define the handle and
[TraceLoggingRegister](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingregister) to
register it.

An invocation like `TRACELOGGING_DECLARE_PROVIDER(MyProviderHandle)` can be
thought of as similar to code like:

```c
extern "C" const TraceLoggingHProvider MyProviderHandle;
```

> [!NOTE]
> The provider handle declared by `TRACELOGGING_DECLARE_PROVIDER` has
> module scope. It can be used as needed within the EXE, DLL, or SYS file but
> should not be shared with other DLLs in the same process. Each EXE, DLL, or
> SYS file should define its own provider handle and should perform its own
> Register and Unregister.

## See also

[TRACELOGGING_DEFINE_PROVIDER](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-tracelogging_define_provider)

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TraceLogging wrapper macros](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)