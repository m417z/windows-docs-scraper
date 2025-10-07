# ENCRYPTION_PROTECTOR structure

Under WIP policy, includes a single identity that a file is protected to.

## Members

### TotalLength

Total length of the **ENCRYPTION_PROTECTOR** in bytes.

### UserSid

The security identifier (SID) of the user the protector belongs to. For more information, see [SID (winnt.h)](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-sid)

### ProtectorDescriptor

Identity the file is protected to (such as contoso.com) from a WIP policy.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------|
| Minimum supported client | Windows 10 |
| Minimum supported server | Windows 10 |
| Header | None |

