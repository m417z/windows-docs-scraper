# CAPICOM\_SIGNED\_DATA\_VERIFY\_FLAG enumeration

The **CAPICOM\_SIGNED\_DATA\_VERIFY\_FLAG** enumeration indicates what is checked when a [*digital signature*](https://learn.microsoft.com/windows/win32/secgloss/d-gly) is verified.

## Members

| Member | Description | Value |
|--------------------------------------------------|-------------------------------------------------------------------------------------------------------------|-------|
| **CAPICOM\_VERIFY\_SIGNATURE\_ONLY** | Only the signature is checked.<br> | 0 |
| **CAPICOM\_VERIFY\_SIGNATURE\_AND\_CERTIFICATE** | Both the signature and the validity of the certificate used to create the signature are checked.<br> | 1 |

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

