# TF_SELECTIONSTYLE structure

## Description

The **TF_SELECTIONSTYLE** structure represents the style of a selection.

## Members

### `ase`

Specifies the active end of the selection. For more information, see [TfActiveSelEnd](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfactiveselend).

### `fInterimChar`

Indicates if the selection is an interim character. If this value is nonzero, then the selection is an interim character and **ase** will be TF_AE_NONE. If this value is zero, the selection is not an interim character.

## Remarks

An interim character selection spans exactly one character and is visually represented as a solid rectangle that is usually flashing. This is a standard UI element of Korean and some Chinese character compositions. **fInterimChar** is an indication that a specific character is composed. **fInterimChar** can only be nonzero for a single selection. In this case, there will be no caret because the highlight replaces it.

## See also

[TF_SELECTION](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_selection)

[TfActiveSelEnd](https://learn.microsoft.com/windows/win32/api/msctf/ne-msctf-tfactiveselend)