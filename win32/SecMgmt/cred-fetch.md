# CRED\_FETCH enumeration

Defines values that determine how to fetch the credential of a Group Managed Service Account (gMSA).

## Constants

**CredFetchDefault**

Signifies that the operating system should first attempt to retrieve the password from the local cache. If it is time to fetch the password, then the operating system should contact a domain controller for the password. If that fails, then return any cached passwords with the status value of success.

**CredFetchDPAPI**

Returns the local DPAPI credential to the caller. [*Security support providers*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSPs) generally would not require the use of this enumeration.

**CredFetchForced**

Forces the operating system to attempt to read the password from the domain controller. During the password rollover time, the password may have changed at the domain controller and other member hosts, but the gMSA member host recognizes the password as still valid. This can happen due to clock skew issues between different domain controllers. When this value is specified, the operating system determines if there could be a possible password change due to clock skew, and if so, retrieves the password. Otherwise, the cached credential is returned. If there is no cached credential, then the operating system attempts to get one from the domain controller.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | Secpkg.h |

