# TRACE_GUID_INFO structure

## Description

Returned by [EnumerateTraceGuidsEx](https://learn.microsoft.com/windows/desktop/ETW/enumeratetraceguidsex).
Defines the header to the list of sessions that enabled a provider.

## Members

### `InstanceCount`

The number of
[TRACE_PROVIDER_INSTANCE_INFO](https://learn.microsoft.com/windows/desktop/ETW/trace-provider-instance-info)
blocks contained in the list. You can have multiple instances of the same
provider if the provider lives in a DLL that is loaded by multiple processes.

### `Reserved`

Reserved.

## Remarks

Use the size of this structure to access the first
[TRACE_PROVIDER_INSTANCE_INFO](https://learn.microsoft.com/windows/desktop/ETW/trace-provider-instance-info)
block in the list.

For an example, see
[EnumerateTraceGuidsEx](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enumeratetraceguidsex).

## See also

[TRACE_PROVIDER_INSTANCE_INFO](https://learn.microsoft.com/windows/desktop/ETW/trace-provider-instance-info)

[EnumerateTraceGuidsEx](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enumeratetraceguidsex)