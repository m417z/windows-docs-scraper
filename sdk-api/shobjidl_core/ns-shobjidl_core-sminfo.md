# SMINFO structure

## Description

Contains information about an item from a menu band.

## Members

### `dwMask`

Type: **DWORD**

Flags that specify which of the other three members are valid.

#### SMIM_TYPE

The **dwType** member contains valid information.

#### SMIM_FLAGS

The **dwFlags** member contains valid information.

#### SMIM_ICON

The **iIcon** member contains valid information.

### `dwType`

Type: **DWORD**

A flag that indicates whether the item is a string or a separator.

#### SMIT_SEPARATOR

A menu separator.

#### SMIT_STRING

A menu string.

### `dwFlags`

Type: **DWORD**

Flags that contain information about the item and how it should be displayed.

#### SMIF_ICON

Show an icon.

#### SMIF_ACCELERATOR

Underline the character marked with an ampersand.

#### SMIF_DROPTARGET

The item is a drop target.

#### SMIF_SUBMENU

The item has a submenu.

#### SMIF_VOLATILE

Not used.

#### SMIF_CHECKED

The item has a check beside it.

#### SMIF_DROPCASCADE

The item can cascade during a drag-drop operation.

#### SMIF_HIDDEN

Do not display the item.

#### SMIF_DISABLED

Make the item unselectable. It will be displayed in gray and will not respond to user actions.

#### SMIF_TRACKPOPUP

Use [TrackPopupMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-trackpopupmenu) to create the pop-up menu.

#### SMIF_DEMOTED

Display the item in a "demoted"" state.

#### SMIF_ALTSTATE

Display the item in an "altered" state.

#### SMIF_DRAGNDROP

Make the item sensitive to a hovering cursor. If the cursor remains over the item for a sufficient duration, it will execute as if the user had clicked the item.

#### SMIF_NEW

This item is newly installed or should be brought to the user's attention.

### `iIcon`

Type: **int**

When **SMIF_ICON** is set, the index of the requested icon in the toolbar image list.