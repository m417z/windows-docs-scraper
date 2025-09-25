# PROPDESC_VIEW_FLAGS enumeration

## Description

These flags describe properties in property description list strings.

## Constants

### `PDVF_DEFAULT:0`

Show this property by default.

### `PDVF_CENTERALIGN:0x1`

This property should be centered.

### `PDVF_RIGHTALIGN:0x2`

This property should be right aligned.

### `PDVF_BEGINNEWGROUP:0x4`

Show this property as the beginning of the next collection of properties in the view.

### `PDVF_FILLAREA:0x8`

Fill the remainder of the view area with the content of this property.

### `PDVF_SORTDESCENDING:0x10`

Sort this property in reverse (descending) order. Applies to a property in a list of sorted properties.

### `PDVF_SHOWONLYIFPRESENT:0x20`

Show this property only if it is present.

### `PDVF_SHOWBYDEFAULT:0x40`

This property should be shown by default in a view (where applicable).

### `PDVF_SHOWINPRIMARYLIST:0x80`

This property should be shown by default in the primary column selection UI.

### `PDVF_SHOWINSECONDARYLIST:0x100`

This property should be shown by default in the secondary column selection UI.

### `PDVF_HIDELABEL:0x200`

Hide the label of this property if the view normally shows the label.

### `PDVF_HIDDEN:0x800`

This property should not be displayed as a column in the UI.

### `PDVF_CANWRAP:0x1000`

This property can be wrapped to the next row.

### `PDVF_MASK_ALL:0x1bff`

A mask used to retrieve all flags.

## Remarks

These values are defined in propsys.h and propsys.idl.