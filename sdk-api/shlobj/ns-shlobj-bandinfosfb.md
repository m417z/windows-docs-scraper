# BANDINFOSFB structure

## Description

Contains information about a folder band. This structure is used with the [IShellFolderBand::GetBandInfoSFB](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-ishellfolderband-getbandinfosfb) and [IShellFolderBand::SetBandInfoSFB](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-ishellfolderband-setbandinfosfb) methods.

## Members

### `dwMask`

Type: **DWORD**

A mask that indicates which members of this **BANDINFOSFB** structure are valid. One or more of the following values.

#### ISFB_MASK_STATE (0x00000001)

The **dwStateMask** member is valid.

#### ISFB_MASK_BKCOLOR (0x00000002)

The **crBkgnd** member is valid.

#### ISFB_MASK_VIEWMODE (0x00000004)

The **wViewMode** member is valid.

#### ISFB_MASK_SHELLFOLDER (0x00000008)

The **psf** member is valid.

#### ISFB_MASK_IDLIST (0x00000010)

The **pidl** member is valid.

#### ISFB_MASK_COLORS (0x00000020)

The **crBtnLt** and **crBtnDk** members are valid.

### `dwStateMask`

Type: **DWORD**

A mask that indicates which of the **dwState** bits are valid to be set or queried. One or more of the following values.

#### ISFB_STATE_DEFAULT (0x00000000)

None of the **dwState** bits.

#### ISFB_STATE_DEBOSSED (0x00000001)

Displays the object with a debossed state, which is with a sunken appearance.

#### ISFB_STATE_ALLOWRENAME (0x00000002)

Allow renaming and a context menu.

#### ISFB_STATE_NOSHOWTEXT (0x00000004)

Do not show text.

#### ISFB_STATE_CHANNELBAR (0x00000010)

Deprecated.

#### ISFB_STATE_QLINKSMODE (0x00000020)

Deprecated.

#### ISFB_STATE_FULLOPEN (0x00000040)

Maximize when opened.

#### ISFB_STATE_NONAMESORT (0x00000080)

The band does not sort by name.

#### ISFB_STATE_BTNMINSIZE (0x00000100)

The band reports the minimum size of its button when queried.

### `dwState`

Type: **DWORD**

State bits. One of the values listed for **dwStateMask**.

### `crBkgnd`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

A [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) that contains the background color of the band.

### `crBtnLt`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) that contains the light button color.

### `crBtnDk`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) that contains the dark button color.

### `wViewMode`

Type: **WORD**

View mode of the band. One of the following values.

#### ISFBVIEWMODE_SMALLICONS (0x00000001)

Use small icons on the folder band.

#### ISFBVIEWMODE_LARGEICONS (0x00000002)

Use large icons on the folder band.

#### ISFBVIEWMODE_LOGOS (0x00000003a)

**Not supported under Windows Vista or later. Not supported under Internet Explorer version 7 or later.**

### `wAlign`

Type: **WORD**

### `psf`

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to an [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) object.

### `pidl`

Type: **PIDLIST_ABSOLUTE**

A PIDL.