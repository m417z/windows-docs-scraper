# PROPDESC_AGGREGATION_TYPE enumeration

## Description

Describes how property values are displayed when multiple items are selected. For a particular property, PROPDESC_AGGREGATION_TYPE describes how the property should be displayed when multiple items that have a value for the property are selected, such as whether the values should be summed, or averaged, or just displayed with the default "Multiple Values" string.

## Constants

### `PDAT_DEFAULT:0`

Display the string "Multiple Values".

### `PDAT_FIRST:1`

Display the first value in the selection.

### `PDAT_SUM:2`

Display the sum of the selected values. This flag is never returned for data types **VT_LPWSTR**, **VT_BOOL**, and **VT_FILETIME**.

### `PDAT_AVERAGE:3`

Display the numerical average of the selected values. This flag is never returned for data types **VT_LPWSTR**, **VT_BOOL**, and **VT_FILETIME**.

### `PDAT_DATERANGE:4`

Display the date range of the selected values. This flag is returned only for values of the **VT_FILETIME** data type.

### `PDAT_UNION:5`

Display a concatenated string of all the values. The order of individual values in the string is undefined. The concatenated string omits duplicate values; if a value occurs more than once, it appears only once in the concatenated string.

### `PDAT_MAX:6`

Display the highest of the selected values.

### `PDAT_MIN:7`

Display the lowest of the selected values.

## Remarks

These values are defined in propsys.h and propsys.idl.