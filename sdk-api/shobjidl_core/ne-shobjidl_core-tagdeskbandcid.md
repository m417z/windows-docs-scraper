# tagDESKBANDCID enumeration

## Description

These command IDs can be sent to the band object's container with [IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec).

## Constants

### `DBID_BANDINFOCHANGED:0`

Updates all bands or a specific band.

* **To update all bands:** Set *pvaIn* to **NULL**.
* **To update a specific band:** Set *pvaIn->lVal* to the ID of the band to be updated, and *pvaIn->vt* to VT_I4.

### `DBID_SHOWONLY:1`

Turns other bands in the container on or off. Set *pvaIn->vt* to VT_UNKNOWN, and set *pvaIn->punkVal* to one of the following values.

| Value | Result |
| --- | --- |
| pUnk | A pointer to the band object's [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. The desk band pointed to is shown; all other desk bands are hidden. |
| 0 | Hides all desk bands. |
| 1 | Shows all desk bands. |

### `DBID_MAXIMIZEBAND:2`

Maximize the band. Set *pvaIn->ulVal* to the ID of the band to be maximized, and set *pvaIn->vt* to VT_UI4.

### `DBID_PUSHCHEVRON:3`

[Version 5](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Displays a push chevron on a desk band. Set *pvaIn->vt* to VT_I4, set *pvaIn->lVal* to the ID of the desk band, and set the [IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec) method's *nCmdExecOpt* parameter to the band identifier received in the most recent call to IDeskBand::GetBandInfo. The container sends an RB_PUSHCHEVRON message, and the band object receives an RBN_CHEVRONPUSHED notification that prompts it to display the chevron. The band ID is passed back to the band object in the lParam parameter of the RBN_CHEVRONPUSHED message.

### `DBID_DELAYINIT:4`

### `DBID_FINISHINIT:5`

### `DBID_SETWINDOWTHEME:6`

### `DBID_PERMITAUTOHIDE:7`

## Remarks

Set the *pguidCmdGroup* parameter of the [IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec) method to CGID_DeskBand, the *pvaIn* parameter to the value indicated in the command description, and the *nCmdID* parameter to one of the command values listed above.

## See also

[Creating Custom Explorer Bars, Tool Bands, and Desk Bands](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc144099(v=vs.85))