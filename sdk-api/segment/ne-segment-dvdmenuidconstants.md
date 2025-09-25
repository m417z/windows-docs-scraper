# DVDMenuIDConstants enumeration

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **DVDMenuID** constants define menu type ID numbers used to display specific menus.

## Constants

### `dvdMenu_Title:2`

Title menu, also called the Video Manager Menu.

### `dvdMenu_Root`

Root menu, the menu for one video title set, which can contain one title or a group of titles.

### `dvdMenu_Subpicture`

Subpicture menu.

### `dvdMenu_Audio`

Audio menu.

### `dvdMenu_Angle`

Angle menu.

### `dvdMenu_Chapter`

Chapter menu.

## Remarks

All the titles in a title set share the same Subpicture, Audio, Angle, and Chapter menus.

## See also

[MSVidWebDVD Constants](https://learn.microsoft.com/previous-versions/dd695183(v=vs.85))

[ShowMenu](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-showmenu)