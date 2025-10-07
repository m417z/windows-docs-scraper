# HANDOFFENTRY structure

The **HANDOFFENTRY** structure defines a specific protocol entry in a **HANDOFFTABLE** structure.

This structure is filled in by Network Monitor based on information in a user supplied .ini file provided when calling the [**CreateHandoffTable**](https://learn.microsoft.com/windows/win32/netmon2/createhandofftable) function. This structure should never be explicitly modified by an application.

## Members

**hoe\_sig**

Signature that identifies this entry as a handoff table entry.

**hoe\_ProtIdentNumber**

Protocol number provided by user supplied .ini file.

**hoe\_ProtocolHandle**

Handle of protocol created using the protocol name provided by user supplied .ini file.

**hoe\_ProtocolData**

Protocol instance data provided by user supplied .ini file.

## Remarks

This structure is filled in by Network Monitor when Network Monitor creates a handoff table.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[HANDOFFTABLE](https://learn.microsoft.com/windows/win32/netmon2/handofftable)

