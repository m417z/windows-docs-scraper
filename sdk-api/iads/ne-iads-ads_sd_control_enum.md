# ADS_SD_CONTROL_ENUM enumeration

## Description

The **ADS_SD_CONTROL_ENUM** enumeration specifies control flags for a security descriptor.

## Constants

### `ADS_SD_CONTROL_SE_OWNER_DEFAULTED:0x1`

A default mechanism provides the owner security identifier (SID) of the security descriptor rather than the original provider of the security descriptor.

### `ADS_SD_CONTROL_SE_GROUP_DEFAULTED:0x2`

A default mechanism provides the group SID of the security descriptor rather than the original provider of the security descriptor.

### `ADS_SD_CONTROL_SE_DACL_PRESENT:0x4`

The discretionary access-control list (DACL) is present in the security descriptor. If this flag is not set, or if this flag is set and the DACL is **NULL**, the security descriptor allows full access to everyone.

### `ADS_SD_CONTROL_SE_DACL_DEFAULTED:0x8`

The security descriptor uses a default DACL built from the creator's access token.

### `ADS_SD_CONTROL_SE_SACL_PRESENT:0x10`

The system access-control list (SACL) is present in the security descriptor.

### `ADS_SD_CONTROL_SE_SACL_DEFAULTED:0x20`

The security descriptor uses a default SACL built from the creator's access token.

### `ADS_SD_CONTROL_SE_DACL_AUTO_INHERIT_REQ:0x100`

THE DACL of the security descriptor must be inherited.

### `ADS_SD_CONTROL_SE_SACL_AUTO_INHERIT_REQ:0x200`

The SACL of the security descriptor must be inherited.

### `ADS_SD_CONTROL_SE_DACL_AUTO_INHERITED:0x400`

The DACL of the security descriptor supports automatic propagation of inheritable access-control entries (ACEs) to existing child objects.

### `ADS_SD_CONTROL_SE_SACL_AUTO_INHERITED:0x800`

The SACL of the security descriptor supports automatic propagation of inheritable ACEs to existing child objects.

### `ADS_SD_CONTROL_SE_DACL_PROTECTED:0x1000`

The security descriptor will not allow inheritable ACEs to modify the DACL.

### `ADS_SD_CONTROL_SE_SACL_PROTECTED:0x2000`

The security descriptor will not allow inheritable ACEs to modify the SACL.

### `ADS_SD_CONTROL_SE_SELF_RELATIVE:0x8000`

The security descriptor is of self-relative format with all the security information in a continuous block of memory.

## Remarks

For more information, see [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control) under Security in the Platform Software Development Kit (SDK).

Since VBScript cannot read information from a type library, VBScript applications do not understand the symbolic constants as defined above. You should use the numerical constants instead to set the appropriate flags in your VBScript applications. If you want to use the symbolic constants as a good programming practice, you should make explicit declarations of such constants, as done here, in your VBScript applications.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)