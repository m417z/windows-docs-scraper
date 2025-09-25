# TS_SELECTIONSTYLE structure

## Description

The **TS_SELECTIONSTYLE** structure represents the style of a selection.

## Members

### `ase`

Specifies the active end of the selection. For more information, see [TsActiveSelEnd](https://learn.microsoft.com/windows/win32/api/textstor/ne-textstor-tsactiveselend).

### `fInterimChar`

Indicates if the selection is an interim character. If this value is nonzero, then the selection is an interim character and **ase** will be TS_AE_NONE. If this value is zero, the selection is not an interim character.

## Remarks

An interim character selection is the length of one character and is visually represented as a solid rectangle that is usually flashing. This is a standard UI element of Korean and some Chinese character compositions. **fInterimChar** is an indication that a specific character is being composed. **fInterimChar** can only be nonzero for a single selection. In this case, there will be no caret because the highlight takes its place.

## See also

[TS_SELECTION_ACP](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selection_acp)

[TS_SELECTION_ANCHOR](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_selection_anchor)

[TsActiveSelEnd](https://learn.microsoft.com/windows/win32/api/textstor/ne-textstor-tsactiveselend)