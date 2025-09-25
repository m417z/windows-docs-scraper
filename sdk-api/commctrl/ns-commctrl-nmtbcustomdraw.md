# NMTBCUSTOMDRAW structure

## Description

Contains information specific to an [NM_CUSTOMDRAW](https://learn.microsoft.com/windows/desktop/Controls/nm-customdraw-toolbar) notification code sent by a toolbar control.

## Members

### `nmcd`

Type: **[NMCUSTOMDRAW](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-nmcustomdraw)**

[NMCUSTOMDRAW](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-nmcustomdraw) structure that contains general custom draw information. The
**uItemState** member of this structure can be modified so that a toolbar item will be drawn in the specified state without actually changing the item's state.

### `hbrMonoDither`

Type: **[HBRUSH](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HBRUSH that the control will use when drawing the background of marked or dithered items. This member is ignored if TBCDRF_NOMARK is returned from the [NM_CUSTOMDRAW](https://learn.microsoft.com/windows/desktop/Controls/nm-customdraw-toolbar) notification code.

### `hbrLines`

Type: **[HBRUSH](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HBRUSH that the control will use when drawing lines on the buttons.

### `hpenLines`

Type: **[HPEN](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HPEN that the control will use when drawing lines on the buttons.

### `clrText`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) that represents the color that the control will use when drawing text on normal items.

### `clrMark`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**COLORREF** that represents the background color that the control will use when drawing text on marked items.

### `clrTextHighlight`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**COLORREF** that represents the color that the control will use when drawing text on highlighted items.

### `clrBtnFace`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**COLORREF** that represents the face color that the control will use when drawing buttons.

### `clrBtnHighlight`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**COLORREF** that represents the face color that the control will use when drawing highlighted items. An item is highlighted if it has the [TBSTATE_MARKED](https://learn.microsoft.com/windows/desktop/Controls/toolbar-button-states) style and is contained in a toolbar that has the [TBSTYLE_FLAT](https://learn.microsoft.com/windows/desktop/Controls/toolbar-control-and-button-styles) style.

### `clrHighlightHotTrack`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**COLORREF** that represents the background color that the control will use when drawing text on hot tracked items. This member is ignored if TBCDRF_HILITEHOTTRACK is not returned from the [NM_CUSTOMDRAW](https://learn.microsoft.com/windows/desktop/Controls/nm-customdraw-toolbar) notification code.

### `rcText`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that, on entry, contains the rectangle of the item's text. The
**right** and
**bottom** members of this structure can be modified to change the width and height, respectively, of the text rectangle of the item.

### `nStringBkMode`

Type: **int**

Background mode that the control will use when drawing the text of a nonhighlighted item. This can be either the TRANSPARENT or OPAQUE value.

### `nHLStringBkMode`

Type: **int**

Background mode that the control will use when drawing the text of a highlighted item. This can be either the TRANSPARENT or OPAQUE value.

### `iListGap`

Type: **int**

[Version 6.0](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) Specifies the distance between the toolbar button image and the text, in logical pixels, for toolbars that have [TBSTYLE_LIST](https://learn.microsoft.com/windows/desktop/Controls/toolbar-control-and-button-styles) style set.

Note that Comctl32.dll version 6 is not redistributable but it is included in Windows or later. To use Comctl32.dll version 6, specify it in a manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).