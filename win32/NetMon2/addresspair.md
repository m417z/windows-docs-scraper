# ADDRESSPAIR structure

The **ADDRESSPAIR** structure constructs a capture filter.

## Members

**AddressFlags**

Flags that describe the addresses used by a capture filter. See Remarks for more information.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------|
| **ADDRESS\_FLAGS\_MATCH\_DST** | Matches the destination address.<br> |
| **ADDRESS\_FLAGS\_MATCH\_SRC** | Matches the source address.<br> |
| **ADDRESS\_FLAGS\_EXCLUDED** | Excludes the frame if this address is found.<br> |
| **ADDRESS\_FLAGS\_DST\_GROUP\_ADDR** | Matches group bit only. Use this for broadcast-type messages.<br> |
| **ADDRESS\_FLAGS\_MATCH\_BOTH** | Matches destination and source addresses.<br> |

**NalReserved**

This is reserved.

**DstAddress**

Destination address of the address pair element.

**SrcAddress**

Source address of the address pair element.

## Remarks

The flags of the **AddressFlags** member can be combined. For example the following setting excludes the frame if the specified source address is detected.

``` syntax
ADDRESS_FLAGS_MATCH_SOURCE|ADDRESS_FLAGS_EXCLUDED
```

For more information about implementing this structure, see [Capture Filters](https://learn.microsoft.com/windows/win32/netmon2/capture-filters).

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[CAPTUREFILTER](https://learn.microsoft.com/windows/win32/netmon2/capturefilter)

