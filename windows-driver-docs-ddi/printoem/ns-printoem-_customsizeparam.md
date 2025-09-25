## Description

The **CUSTOMSIZEPARAM** structure holds information pertaining to a single custom page size parameter for a printer.

## Members

### `dwOrder`

Specifies the order in which a custom page size parameter is placed on the PostScript interpreter's operand stack. For example, a parameter for which **dwOrder** is set to 1 is placed on the stack first. A parameter for which **dwOrder** is set to 2 is placed on the stack second, and so on.

### `lMinVal`

Specifies the minimum value of the custom page size parameter.

### `lMaxVal`

Specifies the maximum value of the custom page size parameter.

## Remarks

The custom page size parameters include Width, Height, WidthOffset, HeightOffset, and Orientation. For Orientation, **lMinVal** and **lMaxVal** are values in the range [0, 3]. For the other custom page size parameters, **lMinVal** and **lMaxVal** values are in units of microns.

## See also

[EATTRIBUTE_DATATYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ne-printoem-_eattribute_datatype)