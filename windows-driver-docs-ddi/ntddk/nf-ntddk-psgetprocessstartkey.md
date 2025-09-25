## Description

This routine generates an identifier for a process which is unique across boot sessions.

## Parameters

### `Process` [in]

A pointer to the EPROCESS structure that represents the process. Drivers can use the [**PsGetCurrentProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentprocess) and [**ObReferenceObjectByHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) routines to obtain a pointer to the EPROCESS structure for a process.

## Return value

Returns a ULONGLONG specifying a unique identifier for the provided process.

## Remarks

Here is an example of how a driver might call this routine:

```cpp
ULONGLONG ProcessStartKey;
ProcessStartKey = PsGetProcessStartKey(PsGetCurrentProcess());
```

The process start key is typically used to track or identify a process over time.

## See also