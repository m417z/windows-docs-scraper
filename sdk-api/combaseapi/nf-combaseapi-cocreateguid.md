# CoCreateGuid function

## Description

Creates a GUID, a unique 128-bit integer used for CLSIDs and interface identifiers.

## Parameters

### `pguid` [out]

A pointer to the requested GUID.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The GUID was successfully created. |

Errors returned by [UuidCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidcreate) are wrapped as an **HRESULT**.

## Remarks

The **CoCreateGuid** function calls the RPC function [UuidCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidcreate), which creates a GUID, a globally unique 128-bit integer. Use **CoCreateGuid** when you need an absolutely unique number that you will use as a persistent identifier in a distributed environment. To a very high degree of certainty, this function returns a unique value – no other invocation, on the same or any other system (networked or not), should return the same value.

## See also

[UuidCreate](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidcreate)