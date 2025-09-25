# ATTRIBUTEPROPERTIES enumeration

## Description

The values of the
**ATTRIBUTEPROPERTIES** type enumerate properties for a RADIUS dictionary attribute.

## Constants

### `PROPERTY_ATTRIBUTE_ID`

The ID of the attribute.

### `PROPERTY_ATTRIBUTE_VENDOR_ID`

The vendor ID for Vendor Specific Attributes (VSA).

### `PROPERTY_ATTRIBUTE_VENDOR_TYPE_ID`

The vendor-specific type ID for Vendor Specific Attributes (VSA).

### `PROPERTY_ATTRIBUTE_IS_ENUMERABLE`

Specifies whether the attribute is enumerable.

### `PROPERTY_ATTRIBUTE_ENUM_NAMES`

The IDs for an enumerable attribute.

### `PROPERTY_ATTRIBUTE_ENUM_VALUES`

The values for an enumerable attribute.

### `PROPERTY_ATTRIBUTE_SYNTAX`

Specifies the syntax of the attribute.

### `PROPERTY_ATTRIBUTE_ALLOW_MULTIPLE`

Specifies whether multiple instances of this attribute are allowed.

### `PROPERTY_ATTRIBUTE_ALLOW_LOG_ORDINAL`

Specifies the Open Database Connectivity (ODBC) ordinal.

### `PROPERTY_ATTRIBUTE_ALLOW_IN_PROFILE`

Specifies whether this attribute is allowed in the profile for a Network Access Policy (NAP).

### `PROPERTY_ATTRIBUTE_ALLOW_IN_CONDITION`

Specifies whether this attribute is allowed in a condition for a Network Access Policy (NAP).

### `PROPERTY_ATTRIBUTE_DISPLAY_NAME`

The display name for the attribute.

### `PROPERTY_ATTRIBUTE_VALUE`

Specifies the value for the attribute.

### `PROPERTY_ATTRIBUTE_ALLOW_IN_PROXY_PROFILE`

Specifies whether the attribute is allowed in an NAP profile for a network request proxy.

### `PROPERTY_ATTRIBUTE_ALLOW_IN_PROXY_CONDITION`

Specifies whether the attribute is allowed in an NAP condition for a network request proxy.

### `PROPERTY_ATTRIBUTE_ALLOW_IN_VPNDIALUP`

Used by NPS user interface to mark whether an attribute is used in profiles for VPN scenario.

### `PROPERTY_ATTRIBUTE_ALLOW_IN_8021X`

Used by NPS user interface to mark whether an attribute is used in profiles for 802.1X scenario.

### `PROPERTY_ATTRIBUTE_ENUM_FILTERS`

Used by filter configuration attributes [MS_ATTRIBUTE_FILTER](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-attributeid) and [MS_ATTRIBUTE_QUARANTINE_IPFILTER](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-attributeid). See MS-Filter section in [RFC 2548](https://www.ietf.org/rfc/rfc2548.txt) for more information.

## Remarks

The
[DICTIONARYPROPERTIES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-dictionaryproperties) enumeration type contains the attributes collection property, **PROPERTY_DICTIONARY_ATTRIBUTES_COLLECTION**.

## See also

[ATTRIBUTEID](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-attributeid)

[ATTRIBUTESYNTAX](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-attributesyntax)

[DICTIONARYPROPERTIES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-dictionaryproperties)