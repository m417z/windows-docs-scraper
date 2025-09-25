# PROPERTY_METRICS structure

## Description

Defines the range and resolution of a packet property.

## Members

### `nLogicalMin`

The minimum value, in logical units, that the tablet reports for this property. For example, a tablet reporting x-values from 0 to 9000 has a logical minimum of 0.

### `nLogicalMax`

The maximum value, in logical units, that the tablet reports for this property. For example, a tablet reporting x-values from 0 to 9000 has a logical maximum of 9000.

### `Units`

 The physical units of the property, such as inches or degrees. For a list of property units, see the [PROPERTY_UNITS](https://learn.microsoft.com/windows/desktop/api/tpcshrd/ne-tpcshrd-property_units) enumeration type.

### `fResolution`

 The resolution or increment value for the `Units` member. For example, a tablet that reports 400 dots per inch (dpi) has an *fResoution* value of 400.

## See also

[PACKET_PROPERTY Structure](https://learn.microsoft.com/windows/desktop/api/tpcshrd/ns-tpcshrd-packet_property)

[PROPERTY_UNITS Enumeration](https://learn.microsoft.com/windows/desktop/api/tpcshrd/ne-tpcshrd-property_units)