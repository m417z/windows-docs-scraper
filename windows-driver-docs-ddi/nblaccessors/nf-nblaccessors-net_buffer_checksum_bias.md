# NET_BUFFER_CHECKSUM_BIAS macro

## Description

**NET_BUFFER_CHECKSUM_BIAS** is a macro that NDIS drivers use to get the **ChecksumBias** member of a [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Syntax

```cpp
#define NET_BUFFER_CHECKSUM_BIAS(_NB) ((_NB)->ChecksumBias)
```

## Parameters

### `_NB`

A pointer to a **NET_BUFFER** structure.

## Return value

**NET_BUFFER_CHECKSUM_BIAS** returns the value of the **ChecksumBias** member of the indicated **NET_BUFFER** structure.

## Remarks

The return value specifies the number of bytes of data to skip over at the beginning of the data buffer when computing a checksum. This value is used by the TCP/IP protocol.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)