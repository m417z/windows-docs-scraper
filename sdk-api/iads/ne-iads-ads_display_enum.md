# ADS_DISPLAY_ENUM enumeration

## Description

The **ADS_DISPLAY_ENUM** enumeration specifies how a path is to be displayed.

## Constants

### `ADS_DISPLAY_FULL:1`

The path is displayed with both attributes and values. For example, CN=Jeff Smith.

### `ADS_DISPLAY_VALUE_ONLY:2`

The path is displayed with values only. For example, Jeff Smith.

## Remarks

This enumeration is used in [IADsPathname::SetDisplayType](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspathname-setdisplaytype) method to specify how a path is to be displayed.

**Note** Because VBScript cannot read data from a type library, VBScript applications do not understand the symbolic constants as defined above. You should use the numeric constants instead to set the appropriate flags in your VBScript applications. If you want to use the symbolic constants as a good programming practice, you should create explicit declarations of such constants, as done here, in your VBScript applications.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[IADsPathname::SetDisplayType](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspathname-setdisplaytype)