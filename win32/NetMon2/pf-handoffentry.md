# PF\_HANDOFFENTRY structure

The **PF\_HANDOFFENTRY** structure defines a protocol that Network Monitor adds to the handoff set of a parser.

## Members

**szIniFile**

Name of the INI file associated with the protocol.

**szIniSection**

Section label within the INI file.

**szProtocol**

Name of the protocol.

**dwHandOffValue**

Value associated with the protocol.

**ValueFormatBase**

Numeric base of the protocol value that is specified in **dwHandOffValue**. The **ValueFormatBase** function must be set to one of the following:

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------|
|

**HANDOFF\_VALUE\_FORMAT\_BASE\_UNKNOWN**

| Unknown base<br> |
|

**HANDOFF\_VALUE\_FORMAT\_BASE\_DECIMAL**

| Decimal base<br> |
|

**HANDOFF\_VALUE\_FORMAT\_BASE\_HEX**

| Hexadecimal base<br> |

## Remarks

An array of the **PF\_HANDOFFENTRY** structures is used in the [PF\_HANDOFFSET](https://learn.microsoft.com/windows/win32/netmon2/pf-handoffset) structure.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[PF\_HANDOFFSET](https://learn.microsoft.com/windows/win32/netmon2/pf-handoffset)

