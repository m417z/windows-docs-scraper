# DS_MANGLE_FOR enumeration

## Description

The **DS_MANGLE_FOR** enumeration is used to define whether a
relative distinguished name is mangled (encoded) and in what form the mangling occurs.

## Constants

### `DS_MANGLE_UNKNOWN:0`

Indicates that the relative distinguished name is not mangled or that the type of mangling is
unknown.

### `DS_MANGLE_OBJECT_RDN_FOR_DELETION`

Indicates that the relative distinguished name has been mangled for deletion.

### `DS_MANGLE_OBJECT_RDN_FOR_NAME_CONFLICT`

Indicates that the relative distinguished name has been mangled due to a naming conflict.

## See also

[DsCrackUnquotedMangledRdn](https://learn.microsoft.com/windows/desktop/api/dsparse/nf-dsparse-dscrackunquotedmangledrdna)

[DsIsMangledDn](https://learn.microsoft.com/windows/desktop/api/dsparse/nf-dsparse-dsismangleddna)

[DsIsMangledRdnValue](https://learn.microsoft.com/windows/desktop/api/dsparse/nf-dsparse-dsismangledrdnvaluea)

[Enumerations in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/enumerations-in-active-directory-domain-services)