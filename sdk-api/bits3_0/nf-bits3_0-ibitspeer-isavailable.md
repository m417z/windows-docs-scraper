# IBitsPeer::IsAvailable

## Description

Determines whether the peer is available (online) to serve content.

## Parameters

### `pOnline` [out]

**TRUE** if the peer is available to serve content, otherwise, **FALSE**.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

If this peer goes offline while BITS is downloading content from it, BITS immediately begins downloading from the origin server.

If the peer stays offline for an extended period of time, BITS removes the peer from the neighborhood.

## See also

[IBitsPeer](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeer)