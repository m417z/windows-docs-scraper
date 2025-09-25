# KSPROPERTY_SERIALHDR structure

## Description

The format of the serialization buffer is a KSPROPERTY_SERIALHDR structure, followed by serialized properties.

## Members

### `PropertySet`

Specifies the GUID of the property set contained in the serialized buffer.

### `Count`

Specifies the count of serialized properties to follow.

## See also

[KSPROPERTY_SERIAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_serial)