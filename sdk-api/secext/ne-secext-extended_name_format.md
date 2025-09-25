# EXTENDED_NAME_FORMAT enumeration

## Description

Specifies a format for a directory service object name.

## Constants

### `NameUnknown:0`

An unknown name type.

### `NameFullyQualifiedDN:1`

The fully qualified distinguished name (for example, CN=Jeff Smith,OU=Users,DC=Engineering,DC=Microsoft,DC=Com).

### `NameSamCompatible:2`

A legacy account name (for example, Engineering\JSmith). The domain-only version includes trailing backslashes (\\).

### `NameDisplay:3`

A "friendly" display name (for example, Jeff Smith). The display name is not necessarily the defining relative distinguished name (RDN).

### `NameUniqueId:6`

A GUID string that the
[IIDFromString](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-iidfromstring) function returns (for example, {4fa050f0-f561-11cf-bdd9-00aa003a77b6}).

### `NameCanonical:7`

The complete canonical name (for example, engineering.microsoft.com/software/someone). The domain-only version includes a trailing forward slash (/).

### `NameUserPrincipal:8`

The user principal name (for example, someone@example.com).

### `NameCanonicalEx:9`

The same as NameCanonical except that the rightmost forward slash (/) is replaced with a new line character (\n), even in a domain-only case (for example, engineering.microsoft.com/software\nJSmith).

### `NameServicePrincipal:10`

The generalized service principal name (for example, www/www.microsoft.com@microsoft.com).

### `NameDnsDomain:12`

The DNS domain name followed by a backward-slash and the SAM user name.

### `NameGivenName:13`

The first name or given name of the user. Note: This type is only available for **GetUserNameEx** calls for an Active Directory user.

### `NameSurname:14`

The last name or surname of the user. Note: This type is only available for **GetUserNameEx** calls for an Active Directory user.

## See also

[GetComputerObjectName](https://learn.microsoft.com/windows/desktop/api/secext/nf-secext-getcomputerobjectnamea)

[GetUserNameEx](https://learn.microsoft.com/windows/desktop/api/secext/nf-secext-getusernameexa)

[TranslateName](https://learn.microsoft.com/windows/desktop/api/secext/nf-secext-translatenamea)