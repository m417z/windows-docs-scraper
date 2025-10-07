# HANDOFFTABLE structure

The **HANDOFFTABLE** structure defines the protocols of a handoff table.

This structure is filled in by Network Monitor based on information in a user supplied .ini file provided when calling the [**CreateHandoffTable**](https://learn.microsoft.com/windows/win32/netmon2/createhandofftable) function.

## Members

**hot\_sig**

Signature that identifies this table as a handoff table.

**hot\_NumEntries**

Number of entries that Network Monitor added to the handoff table.

**hot\_Entries**

Handoff table.

## Remarks

This structure, and its associated HANDOFFENTRY structures, are filled in by Network Monitor when Network Monitor creates a handoff table.

The protocol information that is used when creating a handoff table is provided in an .ini file supplied by the application when [**CreateHandoffTable**](https://learn.microsoft.com/windows/win32/netmon2/createhandofftable) is called.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[HANDOFFENTRY](https://learn.microsoft.com/windows/win32/netmon2/handoffentry)

[CreateHandoffTable](https://learn.microsoft.com/windows/win32/netmon2/createhandofftable)

