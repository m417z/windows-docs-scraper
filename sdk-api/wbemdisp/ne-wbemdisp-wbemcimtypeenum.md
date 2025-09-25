# WbemCimtypeEnum enumeration

## Description

The
WbemCimtypeEnum constants define the valid CIM types of a property value.

The WMI scripting type library, wbemdisp.tlb, defines these constants. Visual Basic applications can access this library; script languages must use the value of the constant directly, unless they use the Windows Script Host (WSH) XML file format. For more information, see
[Using the WMI Scripting Type Library](https://learn.microsoft.com/windows/desktop/WmiSdk/using-the-wmi-scripting-type-library).

## Constants

### `wbemCimtypeSint8:16`

Signed 8-bit integer

### `wbemCimtypeUint8:17`

Unsigned 8-bit integer

### `wbemCimtypeSint16:2`

Signed 16-bit integer

### `wbemCimtypeUint16:18`

Unsigned 16-bit integer

### `wbemCimtypeSint32:3`

Signed 32-bit integer

### `wbemCimtypeUint32:19`

Unsigned 32-bit integer

### `wbemCimtypeSint64:20`

Signed 64-bit integer

### `wbemCimtypeUint64:21`

Unsigned 64-bit integer

### `wbemCimtypeReal32:4`

32-bit real number

### `wbemCimtypeReal64:5`

64-bit real number

### `wbemCimtypeBoolean:11`

Boolean value

### `wbemCimtypeString:8`

String

### `wbemCimtypeDatetime:101`

Date/time value

### `wbemCimtypeReference:102`

Reference to a CIM object

### `wbemCimtypeChar16:103`

16-bit character

### `wbemCimtypeObject:13`

CIM object

## See also

[CIMTYPE_ENUMERATION](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-cimtype_enumeration)

[Scripting API Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/scripting-api-constants)