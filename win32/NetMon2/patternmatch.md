# PATTERNMATCH structure

The **PATTERNMATCH** structure defines pattern elements used to evaluate a frame.

## Members

**Flags**

Pattern match flags:

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------|
|

**PATTERN\_MATCH\_FLAGS\_NOT**

0x00000001

| When set, this flag retains frames that lack the specified pattern in the proper spot.<br> |
|

**PATTERN\_MATCH\_FLAGS\_PORT\_SPECIFIED**

0x00000008

| Seeks a port number value.<br> |

**OffsetBasis**

Types of offset, which can be one of the following:

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------|
|

**OFFSET\_BASIS\_RELATIVE\_TO\_FRAME**

| Sets an offset, in bytes, relative to start of the frame.<br> |
|

**OFFSET\_BASIS\_RELATIVE\_TO\_EFFECTIVE\_PROTOCOL**

| Sets an offset, in bytes, relative to the start of the referenced protocol.<br> |
|

**OFFSET\_BASIS\_RELATIVE\_TO\_IPX**

| Sets an offset, in bytes, only relative to IPX.<br> |
|

**OFFSET\_BASIS\_RELATIVE\_TO\_IP**

| Sets an offset, in bytes, only relative to IP.<br> |

**Port**

Port value, if specified.

**Offset**

The offset, in bytes, relative to the **OffsetBasis**.

**Length**

Length of the matched pattern.

**PatternToMatch**

Pattern to match.

## Remarks

This structure is used to construct a capture filter. For more information about implementing this structure, see [Capture Filters](https://learn.microsoft.com/windows/win32/netmon2/capture-filters).

A capture filter can contain up to four **PATTERNMATCH** structures.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[CAPTUREFILTER](https://learn.microsoft.com/windows/win32/netmon2/capturefilter)

