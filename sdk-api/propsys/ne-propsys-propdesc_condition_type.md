# PROPDESC_CONDITION_TYPE enumeration

## Description

Describes the condition type to use when displaying the property in the query builder UI in Windows Vista, but not in Windows 7 and later.

## Constants

### `PDCOT_NONE:0`

The default value; it means the condition type is unspecified.

### `PDCOT_STRING:1`

Use the string condition type.

### `PDCOT_SIZE:2`

Use the size condition type.

### `PDCOT_DATETIME:3`

Use the date/time condition type.

### `PDCOT_BOOLEAN:4`

Use the Boolean condition type.

### `PDCOT_NUMBER:5`

Use the number condition type.

## Remarks

The flags in PROPDESC_CONDITION_TYPE affected the query string display in the **Advanced Query Builder** user interface in Windows Vista. In Windows 7 and later, the flags in PROPDESC_CONDITION_TYPE are not used.