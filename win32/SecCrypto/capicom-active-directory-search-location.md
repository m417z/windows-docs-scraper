# CAPICOM\_ACTIVE\_DIRECTORY\_SEARCH\_LOCATION enumeration

The **CAPICOM\_ACTIVE\_DIRECTORY\_SEARCH\_LOCATION** enumeration type indicates the location to be searched for an Active Directory [*certificate store*](https://learn.microsoft.com/windows/win32/secgloss/c-gly).

## Members

| Member | Description | Value |
|--------------------------------------|----------------------------------------------|-------|
| **CAPICOM\_SEARCH\_ANY** | Searches all available locations.<br> | 0 |
| **CAPICOM\_SEARCH\_GLOBAL\_CATALOG** | Searches only the global catalog.<br> | 1 |
| **CAPICOM\_SEARCH\_DEFAULT\_DOMAIN** | Searches only the default domain.<br> | 2 |

## Remarks

This enumeration type is used by the following property:

- [**Settings.ActiveDirectorySearchLocation**](https://learn.microsoft.com/windows/win32/seccrypto/settings-activedirectorysearchlocation)

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

