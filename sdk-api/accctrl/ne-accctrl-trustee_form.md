# TRUSTEE_FORM enumeration

## Description

The **TRUSTEE_FORM** enumeration contains values that indicate the type of data pointed to by the **ptstrName** member of the
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure.

## Constants

### `TRUSTEE_IS_SID`

The **ptstrName** member is a pointer to a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) that identifies the trustee.

### `TRUSTEE_IS_NAME`

The **ptstrName** member is a pointer to a null-terminated string that identifies the trustee.

### `TRUSTEE_BAD_FORM`

Indicates a trustee form that is not valid.

### `TRUSTEE_IS_OBJECTS_AND_SID`

The **ptstrName** member is a pointer to an
[OBJECTS_AND_SID](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_sid) structure that contains the SID of the trustee and the GUIDs of the object types in an object-specific [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE).

### `TRUSTEE_IS_OBJECTS_AND_NAME`

The **ptstrName** member is a pointer to an
[OBJECTS_AND_NAME](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_name_a) structure that contains the name of the trustee and the names of the object types in an object-specific ACE.

## See also

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Authorization Enumerations](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-enumerations)

[OBJECTS_AND_NAME](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_name_a)

[OBJECTS_AND_SID](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-objects_and_sid)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)