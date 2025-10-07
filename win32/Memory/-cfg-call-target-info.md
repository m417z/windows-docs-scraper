# CFG\_CALL\_TARGET\_INFO structure

Represents information about call targets for Control Flow Guard (CFG).

## Members

**Offset**

Offset relative to a provided (start) virtual address. This offset should be 16 byte aligned.

**Flags**

Flags describing the operation to be performed on the address. If **CFG\_CALL\_TARGET\_VALID** is set, then the address will be marked valid for CFG. Otherwise, it will be marked an invalid call target.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\]<br> |
| Header<br> | Ntmmapi.h |

