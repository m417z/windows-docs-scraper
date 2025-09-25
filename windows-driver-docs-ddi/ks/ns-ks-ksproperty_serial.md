# KSPROPERTY_SERIAL structure

## Description

The **KSPROPERTY_SERIAL** structure is a header that is included for each property that follows a **KSPROPERTY_SERIALHDR** structure.

## Members

### `PropTypeSet`

A structure of type [**KSIDENTIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksidentifier) that specifies the type of property data. This is the same information obtained from querying Basic Support.

### `Id`

Specifies the identifier for this property.

### `PropertyLength`

Specifies the length, in bytes, of the following property data. This does not include any alignment buffering that may be appended to the property data before the next property in the serialization.

## Remarks

A **KSPROPERTY_SERIAL** structure is followed by the property data, with the start of each property on FILE_LONG_ALIGNMENT. Note that the serial header structure itself is also defined to be on FILE_LONG_ALIGNMENT.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[**KSPROPERTY_SERIALHDR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_serialhdr)