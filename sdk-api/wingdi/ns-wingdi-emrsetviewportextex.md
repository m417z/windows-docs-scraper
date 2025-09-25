# EMRSETVIEWPORTEXTEX structure

## Description

The **EMRSETVIEWPORTEXTEX** and **EMRSETWINDOWEXTEX** structures contains members for the **SetViewportExtEx** and **SetWindowExtEx** enhanced metafile records.

## Members

### `emr`

Base structure for all record types.

### `szlExtent`

Horizontal and vertical extents. For **SetViewportExtEx**, the extents are in device units, and for **SetWindowExtEx**, the extents are in logical units.

## See also

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)