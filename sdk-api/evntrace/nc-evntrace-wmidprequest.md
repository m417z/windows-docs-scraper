## Description

A
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)-based
("Classic") event provider implements this function to receive enable or disable
notification requests from controllers.

The **WMIDPREQUEST** type defines a pointer to this callback function.
**ControlCallback** is a placeholder for the application-defined function name.

## Parameters

### `RequestCode` [in]

Request code. This will be one of the following values.

| Value | Meaning |
| ---------------------- | ------------------------------------------------------- |
| **WMI_ENABLE_EVENTS** | Enables the provider or changes provider configuration. |
| **WMI_DISABLE_EVENTS** | Disables the provider. |

### `RequestContext`

Provider-defined context. The provider uses the _RequestContext_ parameter of
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)
to specify the context.

### `BufferSize`

Reserved for internal use.

### `Buffer` [in]

Pointer to a [WNODE_HEADER](https://learn.microsoft.com/windows/desktop/ETW/wnode-header) structure that
contains information about the event tracing session for which the provider is
being enabled or disabled.

## Return value

You should return ERROR_SUCCESS if the callback succeeds. Note that ETW ignores
the return value for this function except when a controller calls
[EnableTrace](https://learn.microsoft.com/windows/desktop/ETW/enabletrace) to enable a provider and the
provider has not yet called
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa).
When this occurs, **RegisterTraceGuids** will return the return value of this
callback if the registration was successful.

## Remarks

This function is specified using the
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)
function. When the controller calls the
[EnableTrace](https://learn.microsoft.com/windows/desktop/ETW/enabletrace) function to enable, disable, or
change the enable flags or level, ETW calls this callback. The provider enables
or disables itself based on the _RequestCode_ value. Typically, the provider uses
this value to set a global flag to indicate its enabled state.

The provider defines its interpretation of being enabled or disabled. Generally,
if a provider is enabled, it generates events, but while it is disabled, it does
not.

ETW does not pass the enable flags and enable level that the controller passes
to the [EnableTrace](https://learn.microsoft.com/windows/desktop/ETW/enabletrace) function to this
callback. To retrieve this information, call the
[GetTraceEnableFlags](https://learn.microsoft.com/windows/desktop/ETW/gettraceenableflags) and
[GetTraceEnableLevel](https://learn.microsoft.com/windows/desktop/ETW/gettraceenablelevel) functions,
respectively.

You also need to retrieve the session handle in this callback for future calls.
To retrieve the session handle, call the
[GetTraceLoggerHandle](https://learn.microsoft.com/windows/desktop/ETW/gettraceloggerhandle) function.

Your callback function must not call anything that may incur LoadLibrary (more
specifically, anything that requires a loader lock).

## Examples

For an example implementation of a **ControlCallback** function, see
[Writing Classic Events](https://learn.microsoft.com/windows/desktop/ETW/tracing-events).

## See also

[EnableTrace](https://learn.microsoft.com/windows/desktop/ETW/enabletrace)

[GetTraceEnableFlags](https://learn.microsoft.com/windows/desktop/ETW/gettraceenableflags)

[GetTraceEnableLevel](https://learn.microsoft.com/windows/desktop/ETW/gettraceenablelevel)

[GetTraceLoggerHandle](https://learn.microsoft.com/windows/desktop/ETW/gettraceloggerhandle)

[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)

[WNODE_HEADER](https://learn.microsoft.com/windows/desktop/ETW/wnode-header)