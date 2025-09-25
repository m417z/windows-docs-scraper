# TfActiveSelEnd enumeration

## Description

Elements of the **TfActiveSelEnd** enumeration specify which end of a selected range of text is active.

## Constants

### `TF_AE_NONE:0`

The selected range has no active end. This is typical for selected ranges other than the default selected range.

### `TF_AE_START:1`

The active end is at the start of the selected range.

### `TF_AE_END:2`

The active end is at the end of the selected range.

## Remarks

The active end of a selected range is the end likely to respond to user actions. For example, in many applications, holding the SHIFT key down while using the arrow keys will change the selected range. The end of the selected range that moves is the active end of the selected range.

This enumeration is used in the [TF_SELECTIONSTYLE](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_selectionstyle) structure.

## See also

[TF_SELECTIONSTYLE](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_selectionstyle)