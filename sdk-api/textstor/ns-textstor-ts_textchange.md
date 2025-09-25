# TS_TEXTCHANGE structure

## Description

The **TS_TEXTCHANGE** structure contains text change data.

## Members

### `acpStart`

Contains the starting character position of the change.

### `acpOldEnd`

Contains the ending character position before the text is changed.

### `acpNewEnd`

Contains the ending character position after the text is changed.

## Remarks

The possible text changes include insert, delete, and replace. For example, if you replace the first "t" of "text" with "T", **acpStart** =0, **acpOldEnd** =1, and **acpNewEnd** =1. If you delete the last "t", **acpStart** =3, **acpOldEnd** =4, and **acpNewEnd** =3. If an "a" is inserted between "e" and "x", **acpStart** =2, **acpOldEnd** =2, and **acpNewEnd** =3.