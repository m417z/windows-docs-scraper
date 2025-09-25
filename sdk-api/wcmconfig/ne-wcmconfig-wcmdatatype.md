# WcmDataType enumeration

## Description

Enumerates the data types returned from the [ISettingsItem::GetDataType](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingsitem-getdatatype) method. The values correspond appropriately to typical programming types. An exception is the flag value **dataTypeFlagArray**. This flag may appear combined with **dataTypeByte** or **dataTypeString** to indicate xsd:hexBinary or wcm:multiString settings (respectively).

Each of the following constants correspond to a data type.

## Constants

### `dataTypeByte:1`

Corresponds to a byte.

### `dataTypeSByte:2`

Corresponds to a signed byte.

### `dataTypeUInt16:3`

Corresponds to an unsigned 16-bit integer.

### `dataTypeInt16:4`

Corresponds to a 16-bit integer.

### `dataTypeUInt32:5`

Corresponds to an unsigned 32-bit integer.

### `dataTypeInt32:6`

Corresponds to a 32-bit integer.

### `dataTypeUInt64:7`

Corresponds to an unsigned 64-bit integer.

### `dataTypeInt64:8`

Corresponds to a 64-bit integer.

### `dataTypeBoolean:11`

Corresponds to a Boolean.

### `dataTypeString:12`

Corresponds to a string.

### `dataTypeFlagArray:0x8000`

This flag may appear combined with **dataTypeByte** or **dataTypeString** to indicate xsd:hexBinary or wcm:multiString settings, respectively.