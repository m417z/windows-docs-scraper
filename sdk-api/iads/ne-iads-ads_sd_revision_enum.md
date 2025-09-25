# ADS_SD_REVISION_ENUM enumeration

## Description

The **ADS_SD_REVISION_ENUM** enumeration specifies the revision number of the access-control entry (ACE), or the access-control list (ACL), for Active Directory.

## Constants

### `ADS_SD_REVISION_DS:4`

The revision number of the ACE, or the ACL, for Active Directory.

## Remarks

The **ADS_SD_REVISION_DS** flag signifies that the related ACL contains object-specific ACEs.

Because VBScript cannot read data from a type library, VBScript applications cannot recognize the symbolic constants as defined above. Use the numerical constants instead to set the appropriate flags in your VBScript applications. To use the symbolic constants as a good programming practice, write explicit declarations of such constants, as done here, in your VBScript applications.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)