# ADS_ATTR_DEF structure

## Description

The **ADS_ATTR_DEF** structure is used only as a part of **IDirectorySchemaMgmt**, which is an obsolete interface. The following information is provided for legacy purposes only.

The **ADS_ATTR_DEF** structure describes schema data for an attribute. It is used to manage attribute definitions in the schema.

## Members

### `pszAttrName`

The null-terminated Unicode string that contains the name of the attribute.

### `dwADsType`

Data type of the attribute as defined by [ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum).

### `dwMinRange`

Minimum legal range for this attribute.

### `dwMaxRange`

Maximum legal range for this attribute.

### `fMultiValued`

Whether or not this attribute takes more than one value.

## Remarks

In ADSI, attributes and properties are used interchangeably.

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)

[ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum)