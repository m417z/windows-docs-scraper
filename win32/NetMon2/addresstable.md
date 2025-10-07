# ADDRESSTABLE structure

The **ADDRESSTABLE** structure contains a table of address pairs.

## Members

**nAddressPairs**

Number of address pairs in the **AddressPair** array.

**nNonMacAddressPairs**

Number of non-MAC address pairs.

**AddressPair**

Array of address pairs. Note that you may only store up to eight address pairs per ADDRESSTABLE structure.

## Remarks

Use this structure as part of the capture filter construction process. For more information about implementing this structure, see [Capture Filters](https://learn.microsoft.com/windows/win32/netmon2/capture-filters).

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[ADDRESSPAIR](https://learn.microsoft.com/windows/win32/netmon2/addresspair)

[CAPTUREFILTER](https://learn.microsoft.com/windows/win32/netmon2/capturefilter)

