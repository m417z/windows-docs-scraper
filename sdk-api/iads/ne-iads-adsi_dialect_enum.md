# ADSI_DIALECT_ENUM enumeration

## Description

The **ADSI_DIALECT_ENUM** enumeration specifies query dialects used in the OLE DB provider for ADSI.

## Constants

### `ADSI_DIALECT_LDAP:0`

ADSI queries are based on the LDAP dialect.

### `ADSI_DIALECT_SQL:0x1`

ADSI queries are based on the SQL dialect.

## Remarks

An ActiveX Data Object (ADO) client can use one of the two ADSI query dialects to query a directory. For more information about the ADSI query dialects, see [Searching with ActiveX Data Objects](https://learn.microsoft.com/windows/desktop/ADSI/searching-with-activex-data-objects-ado).

**Note** Because Visual Basic Script (VBScript) cannot read data from a type library, VBScript applications do not recognize the symbolic constants as defined above. Use the numerical constants to set the appropriate flags in your VBScript applications. To use the symbolic constants as a good programming practice, write explicit declarations of such constants, as done here.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)