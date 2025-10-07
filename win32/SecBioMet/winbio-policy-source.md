# WINBIO\_POLICY\_SOURCE enumeration

Lists the possible sources of policy information for the detection of spoofing for biometric factors.

## Constants

**WINBIO\_POLICY\_UNKNOWN**

The source of the policy is unknown.

**WINBIO\_POLICY\_DEFAULT**

The policy is the default policy that the Windows Biometric Framework provides.

**WINBIO\_POLICY\_LOCAL**

The policy that the individual user set for their account by using Windows **Settings**. This policy overrides the default policy.

**WINBIO\_POLICY\_ADMIN**

A group policy that the IT administrator set for the enterprise. Individual users cannot override this policy.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h for client applications or Winbio\_adapters.h for adapters) |

## See also

[**WINBIO\_ANTI\_SPOOF\_POLICY\_ACTION**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-anti-spoof-policy-action)

