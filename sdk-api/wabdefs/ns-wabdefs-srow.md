# SRow structure

## Description

Do not use. Describes a row from a table containing selected properties for a specific object.

## Members

### `ulAdrEntryPad`

Type: **ULONG**

Variable of type **ULONG** that specifies the number of padding bytes for aligning properly the property values to which the **lpProps** member points.

### `cValues`

Type: **ULONG**

Variable of type **ULONG** that specifies the count of property values to which **lpProps** points.

### `lpProps`

Type: **LPSPropValue**

Pointer to an array of variables of type [SPropValue](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-spropvalue) that describe the property values for the columns in the row.