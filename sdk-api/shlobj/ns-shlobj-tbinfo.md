# TBINFO structure

## Description

Used with the [SFVM_GETBUTTONINFO](https://learn.microsoft.com/windows/desktop/shell/sfvm-getbuttoninfo) notification to specify the number of buttons to add to the toolbar, as well as how they're added.

## Members

### `cbuttons`

Type: **UINT**

The number of buttons.

### `uFlags`

Type: **UINT**

One of the following flags.

#### TBIF_APPEND (0)

Add the new buttons after the existing buttons.

#### TBIF_PREPEND (1)

Add the new buttons before the existing buttons.

#### TBIF_REPLACE (2)

Replace the existing buttons with the new buttons.