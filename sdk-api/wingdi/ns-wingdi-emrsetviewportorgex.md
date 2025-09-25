# EMRSETVIEWPORTORGEX structure

## Description

The **EMRSETVIEWPORTORGEX,** **EMRSETWINDOWORGEX,**  and **EMRSETBRUSHORGEX** structures contain members for the **SetViewportOrgEx**, **SetWindowOrgEx**, and **SetBrushOrgEx** enhanced metafile records.

## Members

### `emr`

Base structure for all record types.

### `ptlOrigin`

Coordinates of the origin. For **EMRSETVIEWPORTORGEX** and **EMRSETBRUSHORGEX**, this is in device units. For **EMRSETWINDOWORGEX**, this is in logical units.

## See also

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[SetBrushOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbrushorgex)

[SetViewportOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportorgex)

[SetWindowOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindoworgex)