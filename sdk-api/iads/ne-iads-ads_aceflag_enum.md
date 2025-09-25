# ADS_ACEFLAG_ENUM enumeration

## Description

The **ADS_ACEFLAG_ENUM** enumeration is used to specify the behavior of an Access Control Entry (ACE) for an Active Directory object.

For more information and possible values for file, file share and registry objects, see the **AceFlags** member of the [ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure.

## Constants

### `ADS_ACEFLAG_INHERIT_ACE:0x2`

Child objects will inherit this access-control entry (ACE). The inherited ACE is inheritable unless the ADS_ACEFLAG_NO_PROPAGATE_INHERIT_ACE flag is set.

### `ADS_ACEFLAG_NO_PROPAGATE_INHERIT_ACE:0x4`

The system will clear the ADS_ACEFLAG_INHERIT_ACE flag for the inherited ACEs of child objects. This prevents the ACE from being inherited by subsequent generations of objects.

### `ADS_ACEFLAG_INHERIT_ONLY_ACE:0x8`

Indicates that an inherit-only ACE that does not exercise access control on the object to which it is attached. If this flag is not set, the ACE is an effective ACE that exerts access control on the object to which it is attached.

### `ADS_ACEFLAG_INHERITED_ACE:0x10`

Indicates whether or not the ACE was inherited. The system sets this bit.

### `ADS_ACEFLAG_VALID_INHERIT_FLAGS:0x1f`

Indicates whether the inherit flags are valid. The system sets this bit.

### `ADS_ACEFLAG_SUCCESSFUL_ACCESS:0x40`

Generates audit messages for successful access attempts, used with ACEs that audit the system in a system access-control list (SACL).

### `ADS_ACEFLAG_FAILED_ACCESS:0x80`

Generates audit messages for failed access attempts, used with ACEs that audit the system in a SACL.

## Remarks

Because VBScript cannot read data from a type library, VBScript applications do not understand the symbolic constants as defined in these enumerations. You should use the numerical constants instead to set the appropriate flags in your VBScript applications. If you want to use the symbolic constants as a good programming practice, write explicit declarations of such constants, as done here, in your VBScript applications.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[IADsObjectOptions](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsobjectoptions)

[IADsPathname::Set](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspathname-set)