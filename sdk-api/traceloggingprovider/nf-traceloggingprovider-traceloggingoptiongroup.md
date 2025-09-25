# TraceLoggingOptionGroup macro

## Syntax

```cpp
void TraceLoggingOptionGroup(
  [in]  UINT32 g1,
  [in]   g2,
  [in]   g3,
  [in]   g4,
  [in]   g5,
  [in]   g6,
  [in]   g7,
  [in]   g8,
  [in]   g9,
  [in]   g10,
  [in]   g11
);
```

## Description

TraceLogging macro for use in
[TRACELOGGING_DEFINE_PROVIDER](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-tracelogging_define_provider)
to specify a provider group.

Most TraceLogging providers are not associated with a provider group and do not
need to use TraceLoggingOptionGroup.

## Parameters

### `g1` [in]

The first 4 bytes of the GUID.

### `g2` [in]

The next 2 bytes of the GUID.

### `g3` [in]

The next 2 bytes of the GUID.

### `g4` [in]

The next byte of the GUID.

### `g5` [in]

The next byte of the GUID.

### `g6` [in]

The next byte of the GUID.

### `g7` [in]

The next byte of the GUID.

### `g8` [in]

The next byte of the GUID.

### `g9` [in]

The next byte of the GUID.

### `g10` [in]

The next byte of the GUID.

### `g11` [in]

The next byte of the GUID.

## Remarks

If you want your provider to be associated with an
[ETW provider group](https://learn.microsoft.com/windows/win32/etw/provider-traits), add the
[TraceLoggingOptionGroup](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingoptiongroup)
macro to the
[TRACELOGGING_DEFINE_PROVIDER](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-tracelogging_define_provider)
declaration to specify the provider's group GUID.

A provider can be a member of no more than one group. The semantics of group
membership are determined by ETW controllers that subscribe a session to a group
via [EnableTraceEx2](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enabletraceex2) with
EVENT_ENABLE_PROPERTY_PROVIDER_GROUP.

### Examples

```c
TRACELOGGING_DEFINE_PROVIDER(
    g_hMyProvider,
    "MyProvider",
    // {b3864c38-4273-58c5-545b-8b3608343471}
    (0xb3864c38,0x4273,0x58c5,0x54,0x5b,0x8b,0x36,0x08,0x34,0x34,0x71),
    // {798d0c76-4209-5932-a2af-2d94a2e66c45}
    TraceLoggingOptionGroup(0x798d0c76,0x4209,0x5932,0xa2,0xaf,0x2d,0x94,0xa2,0xe6,0x6c,0x45));
```

## See also

[TraceLoggingWrite](https://learn.microsoft.com/windows/win32/api/traceloggingprovider/nf-traceloggingprovider-traceloggingwrite)

[TraceLogging wrapper macros](https://learn.microsoft.com/windows/desktop/tracelogging/tracelogging-wrapper-macros)

[EnableTraceEx2](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enabletraceex2)

[Provider Traits](https://learn.microsoft.com/windows/win32/etw/provider-traits)