# EMRARC structure

## Description

The **EMRARC,** **EMRARCTO,** **EMRCHORD,**  and **EMRPIE** structures contain members for the [Arc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arc), [ArcTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-arcto), [Chord](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-chord), and [Pie](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-pie) enhanced metafile records.

## Members

### `emr`

Base structure for all record types.

### `rclBox`

Bounding rectangle in logical units.

### `ptlStart`

Coordinates of first radial ending point in logical units.

### `ptlEnd`

Coordinates of second radial ending point in logical units.

## See also

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)