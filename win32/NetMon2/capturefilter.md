# CAPTUREFILTER structure

The **CAPTUREFILTER** structure contains capture filter data.

## Members

**FilterFlags**

Flags that describe the contents of the capture filter.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------|
| **CAPTUREFILTER\_FLAGS\_INCLUDE\_ALL\_SAPS**

0x0001 | Includes all SAPs as acceptable frames.\ | | **CAPTUREFILTER\_FLAGS\_INCLUDE\_ALL\_ETYPES**

0x0002 | Include all Etypes as acceptable frames.\ | | **CAPTUREFILTER\_FLAGS\_LOCAL\_ONLY**

0x0008 | No P-mode\ | | **CAPTUREFILTER\_FLAGS\_KEEP\_RAW**

0x0020 | Keep SMT and token ring MAC frames.\ |

**lpSapTable**

Pointer to an array of SAP values. This member indicates the SAP values that are valid to pass to the driver. If CAPTUREFILTER\_FLAGS\_INCLUDE\_ALL\_SAPS is set, this becomes an exception list (include all SAPS except these).

**lpEtypeTable**

Pointer to an array of Etype values. This indicates those Etype values that are valid to pass to the driver. If CAPTUREFILTER\_FLAGS\_INCLUDE\_ALL\_ETYPES is set, this becomes an exception list (include all Etypes except these).

**nSaps**

Number of SAPs in the SAP table.

**nEtypes**

Number of Etypes in the Etype table.

**AddressTable**

Name of the address table.

**FilterExpression**

An EXPRESSION structure. This contains the pattern match portion of the capture filter.

**Trigger**

Reserved.

**nFrameBytesToCopy**

If this member is not 0, then it specifies how many bytes to keep of each frame received. If it is 0, then keep the whole frame.

**Reserved**

Reserved.

## Remarks

The combination of flags, values, and expressions determine which frames will be passed by the driver that uses this structure data. For more information about implementing a **CAPTUREFILTER** structure, see [Capture Filters](https://learn.microsoft.com/windows/win32/netmon2/capture-filters).

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[ADDRESSTABLE](https://learn.microsoft.com/windows/win32/netmon2/addresstable)

[ADDRESSPAIR](https://learn.microsoft.com/windows/win32/netmon2/addresspair)

[EXPRESSION](https://learn.microsoft.com/windows/win32/netmon2/expression)

[ANDEXP](https://learn.microsoft.com/windows/win32/netmon2/andexp)

[PATTERNMATCH](https://learn.microsoft.com/windows/win32/netmon2/patternmatch)

