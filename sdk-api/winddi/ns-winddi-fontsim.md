# FONTSIM structure

## Description

The FONTSIM structure contains offsets to one or more [FONTDIFF](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontdiff) structures describing bold, italic, and bold italic font simulations.

## Members

### `dpBold`

If nonzero, specifies the offset from the beginning of this structure to the FONTDIFF structure describing the bold simulation. If this member is zero, the font does not support bold simulation.

### `dpItalic`

If nonzero, specifies the offset from the beginning of this structure to the FONTDIFF structure describing the italic simulation. If this member is zero, the font does not support italic simulation.

### `dpBoldItalic`

If nonzero, specifies the offset from the beginning of this structure to the FONTDIFF structure describing the bold italic simulation. If this member is zero, the font does not support bold italic simulation.

## Remarks

If the **dpFontSim** member of the [IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics) structure is nonzero, it holds the offset from the beginning of that structure to the beginning of a FONTSIM structure.

## See also

[FONTDIFF](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fontdiff)

[IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics)