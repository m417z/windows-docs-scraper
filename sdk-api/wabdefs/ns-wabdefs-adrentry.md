# ADRENTRY structure

## Description

Do not use. Describes zero or more properties belonging to one or more recipients.

## Members

### `ulReserved1`

Type: **ULONG**

### `cValues`

Type: **ULONG**

Variable of type **ULONG** that specifies the count of properties in the property value array to which the **rgPropVals** member points. The **cValues** member can be zero.

### `rgPropVals`

Type: **LPSPropValue**

Pointer to a variable of type [SPropValue](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-spropvalue) that specifies the property value array describing the properties for the recipient. The **rgPropVals** member can be **NULL**.