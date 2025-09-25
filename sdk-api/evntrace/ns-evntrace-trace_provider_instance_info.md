# TRACE_PROVIDER_INSTANCE_INFO structure

## Description

Defines an instance of the provider GUID. This data is returned from
[EnumerateTraceGuidsEx](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enumeratetraceguidsex)
when called with the
[TraceGuidQueryInfo](https://learn.microsoft.com/windows/win32/api/evntrace/ne-evntrace-trace_query_info_class)
information class.

## Members

### `NextOffset`

Offset, in bytes, from the beginning of this structure to the next
**TRACE_PROVIDER_INSTANCE_INFO** structure. The value is zero if there is not
another instance info block.

### `EnableCount`

Number of [TRACE_ENABLE_INFO](https://learn.microsoft.com/windows/desktop/ETW/trace-enable-info) structures
in this block. Each structure represents a session that enabled the provider.

### `Pid`

Process identifier of the process that registered the provider.

### `Flags`

Can be one of the following flags.

- **TRACE_PROVIDER_FLAG_LEGACY**: The provider used
[RegisterTraceGuids](https://learn.microsoft.com/windows/desktop/ETW/registertraceguids) instead of
[EventRegister](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventregister) to
register itself.

- **TRACE_PROVIDER_FLAG_PRE_ENABLE**: The provider is not registered; however,
one or more sessions have enabled the provider.

## Remarks

If more than one event provider has registered using the same provider GUID, the
[TRACE_GUID_INFO](https://learn.microsoft.com/windows/desktop/ETW/trace-guid-info) block contains more than
one **TRACE_PROVIDER_INSTANCE_INFO** structure.

## See also

[TRACE_ENABLE_INFO](https://learn.microsoft.com/windows/desktop/ETW/trace-enable-info)

[TRACE_GUID_INFO](https://learn.microsoft.com/windows/desktop/ETW/trace-guid-info)