# EMRPOLYTEXTOUTA structure

## Description

The **EMRPOLYTEXTOUTA** and **EMRPOLYTEXTOUTW** structures contain members for the **PolyTextOut** enhanced metafile record.

## Members

### `emr`

Base structure for all record types.

### `rclBounds`

Bounding rectangle, in device units.

### `iGraphicsMode`

Current graphics mode. This member can be either the GM_COMPATIBLE or GM_ADVANCED value.

### `exScale`

X-scaling factor from page units to .01mm units if the graphics mode is the GM_COMPATIBLE value.

### `eyScale`

Y-scaling factor from page units to .01mm units if the graphics mode is the GM_COMPATIBLE value.

### `cStrings`

Number of strings.

### `aemrtext`

**EMRTEXT** structure, which is followed by the string and the intercharacter spacing array.

## See also

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)