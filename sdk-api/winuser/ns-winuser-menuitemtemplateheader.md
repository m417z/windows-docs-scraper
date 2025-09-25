# MENUITEMTEMPLATEHEADER structure

## Description

Defines the header for a menu template. A complete menu template consists of a header and one or more menu item lists.

## Members

### `versionNumber`

Type: **WORD**

The version number. This member must be zero.

### `offset`

Type: **WORD**

The offset, in bytes, from the end of the header. The menu item list begins at this offset. Usually, this member is zero, and the menu item list follows immediately after the header.

## Remarks

One or more [MENUITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuitemtemplate) structures are combined to form the menu item list.

## See also

**Conceptual**

[LoadMenuIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadmenuindirecta)

[MENUITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-menuitemtemplate)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**