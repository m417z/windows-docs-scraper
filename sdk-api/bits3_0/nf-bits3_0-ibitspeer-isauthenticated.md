# IBitsPeer::IsAuthenticated

## Description

Determines whether the peer is authenticated.

## Parameters

### `pAuth` [out]

**TRUE** if the peer is authenticated, otherwise, **FALSE**.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

BITS cannot download content from an unauthenticated peer. When peers are detected, they are initially not authenticated. BITS contacts peers when downloading a job that is enabled for peercaching; BITS authenticates a given peer the first time it is contacted.

## See also

[IBitsPeer](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeer)