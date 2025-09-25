# WbemObjectTextFormatEnum enumeration

## Description

The
WbemObjectTextFormatEnum constants define the valid object text formats to be used by
[SWbemObjectEx.GetText_](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemobjectex-gettext-).

The WMI scripting type library, wbemdisp.tlb, defines these constants. Visual Basic applications can access this library; script languages must use the value of the constant directly, unless they use Windows Script Host (WSH) XML file format. For more information, see
[Using the WMI Scripting Type Library](https://learn.microsoft.com/windows/desktop/WmiSdk/using-the-wmi-scripting-type-library).

## Constants

### `wbemObjectTextFormatCIMDTD20:1`

XML format conforming to the DMTF (Distributed Management Task Force) CIM document type definition (DTD) version 2.0.

### `wbemObjectTextFormatWMIDTD20:2`

XML format as defined by the extended WMI version of DMTF CIM DTD version 2.0. Using this value enables WMI-specific extensions, such as embedded objects or scope.

#### - WMI_OBJ_TEXT_LAST

Not supported.

#### - WMI_OBJ_TEXT_WMI_EXT1

Not supported.

#### - WMI_OBJ_TEXT_WMI_EXT10

Not supported.

#### - WMI_OBJ_TEXT_WMI_EXT2

Not supported.

#### - WMI_OBJ_TEXT_WMI_EXT3

Not supported.

#### - WMI_OBJ_TEXT_WMI_EXT4

Not supported.

#### - WMI_OBJ_TEXT_WMI_EXT5

Not supported.

#### - WMI_OBJ_TEXT_WMI_EXT6

Not supported.

#### - WMI_OBJ_TEXT_WMI_EXT7

Not supported.

#### - WMI_OBJ_TEXT_WMI_EXT8

Not supported.

#### - WMI_OBJ_TEXT_WMI_EXT9

Not supported.

## See also

[Scripting API Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/scripting-api-constants)

[WbemTextFlagEnum](https://learn.microsoft.com/windows/desktop/api/wbemdisp/ne-wbemdisp-wbemtextflagenum)