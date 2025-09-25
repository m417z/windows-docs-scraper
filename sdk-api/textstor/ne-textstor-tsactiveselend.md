# TsActiveSelEnd enumeration

## Description

Elements of the **TsActiveSelEnd** enumeration specify which end of a text store selection is active.

## Constants

### `TS_AE_NONE:0`

The selection has no active end. This is typical for all selections other than the default selection.

### `TS_AE_START:1`

The active end of the selection is at the start of the range of text.

### `TS_AE_END:2`

The active end of the selection is at the end of the range of text.

## Remarks

The active end of a selection is the end likely to respond to user actions. For example, in many applications, holding down the SHIFT key while using the arrow keys will change the selection. The end of the selection that moves is the active end of the selection.

This enumeration is used in the [TS_SELECTIONSTYLE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selectionstyle) structure.

## See also

[TS_SELECTIONSTYLE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selectionstyle)