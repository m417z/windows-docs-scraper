# CAPICOM\_ATTRIBUTE enumeration

The **CAPICOM\_ATTRIBUTE** enumeration type defines the kind of attribute associated with a [*signature*](https://learn.microsoft.com/windows/win32/secgloss/d-gly).

## Members

| Member | Description | Value |
|--------------------------------------------------------------|----------------------------------------------------------------------------|-------|
| **CAPICOM\_AUTHENTICATED\_ATTRIBUTE\_SIGNING\_TIME** | The attribute contains the time that the signature was created.<br> | 0 |
| **CAPICOM\_AUTHENTICATED\_ATTRIBUTE\_DOCUMENT\_NAME** | The attribute contains the name of the signed document.<br> | 1 |
| **CAPICOM\_AUTHENTICATED\_ATTRIBUTE\_DOCUMENT\_DESCRIPTION** | The attribute contains a description of the signed document.<br> | 2 |

## Remarks

The **CAPICOM\_ATTRIBUTE** enumeration type is used by the [**Attribute.Name**](https://learn.microsoft.com/windows/win32/seccrypto/attribute-name) property.

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

