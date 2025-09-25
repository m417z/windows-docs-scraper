# ADS_PROPERTY_OPERATION_ENUM enumeration

## Description

The **ADS_PROPERTY_OPERATION_ENUM** enumeration specifies ways to update a named property in the cache.

## Constants

### `ADS_PROPERTY_CLEAR:1`

Instructs the directory service to remove all the property value(s) from the object.

### `ADS_PROPERTY_UPDATE:2`

Instructs the directory service to replace the current value(s) with the specified value(s).

### `ADS_PROPERTY_APPEND:3`

Instructs the directory service to append the specified value(s) to the existing values(s).

When the **ADS_PROPERTY_APPEND** operation is specified, the new attribute value(s) are automatically committed to the directory service and removed from the local cache. This forces the local cache to be updated from the directory service the next time the attribute value(s) are retrieved.

### `ADS_PROPERTY_DELETE:4`

Instructs the directory service to delete the specified value(s) from the object.

## Remarks

The elements of this enumeration are used with the [IADs.PutEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-putex) method, the document of which provides an example of how to use these enumerated constants.

Because Visual Basic Scripting Edition (VBScript) cannot read data from a type library, VBScript applications do not recognize the symbolic constants as defined. Use the numeric constants instead to set the appropriate flags in your VBScript applications. To use the symbolic constants as a good programming practice, write explicit declarations of such constants, as done here.

## See also

[ADSI
Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[IADs.PutEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-putex)