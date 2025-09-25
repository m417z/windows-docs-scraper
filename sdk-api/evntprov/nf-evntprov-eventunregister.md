# EventUnregister function

## Description

Unregisters an ETW event provider.

All event providers registered by a component must be unregistered before the
component unloads. If a DLL registers an event provider and then unloads without
unregistering the event provider, the process may crash.

## Parameters

### `RegHandle` [in]

Event provider registration handle returned by
[EventRegister](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventregister).

## Return value

Returns **ERROR_SUCCESS** if successful.

## Remarks

If **EventRegister** fails, it returns a zero-valued RegHandle. ETW APIs such as
**EventWrite** and **EventUnregister** will safely accept a zero-valued
RegHandle value, do nothing, and return immediately. Callers do not need to
check for a zero-valued RegHandle before calling **EventWrite** or
**EventUnregister**.

## See also

[EventRegister](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventregister)