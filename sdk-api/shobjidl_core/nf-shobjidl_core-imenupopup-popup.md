# IMenuPopup::Popup

## Description

Invokes the shortcut menu at a specified onscreen location.

## Parameters

### `ppt` [in]

Type: **[POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl)***

A pointer to a [POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl) structure that specifies the location of the pop-up menu in screen coordinates. The pop-up menu is displayed in relation to this point as determined by the position flags set in *dwFlags*.

### `prcExclude` [in]

Type: **[RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)***

A pointer to a [RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl) structure that specifies the rectangle to exclude when positioning the menu. In Windows Vista, the alignment of the menu in relation to this area is determined by the alignment flags set in *dwFlags*. This parameter can be **NULL** to include the entire screen.

### `dwFlags` [in]

Type: **MP_POPUPFLAGS**

One or more of the following constants that control the display of the pop-up menu.

#### MPPF_SETFOCUS (0x00000001)

The menu should have focus when it appears.

#### MPPF_INITIALSELECT (0x00000002)

The first item in the menu should be selected.

#### MPPF_NOANIMATE (0x00000004)

Do not animate this show.

#### MPPF_KEYBOARD (0x00000010)

The menu is activated by the keyboard.

#### MPPF_REPOSITION (0x00000020)

Reposition the displayed bar.

#### MPPF_FORCEZORDER (0x00000040)

The menu bar should ignore submenu positions.

#### MPPF_FINALSELECT (0x00000080)

The last item in the menu should be selected.

#### MPPF_TOP (0x20000000)

Display the pop-up menu above the point specified in *ppt*.

#### MPPF_LEFT (0x40000000)

Display the pop-up menu to the left of the point specified in *ppt*.

#### MPPF_RIGHT (0x60000000)

Display the pop-up menu to the right of the point specified in *ppt*.

#### MPPF_BOTTOM (0x80000000)

Display the pop-up menu below the point specified in *ppt*.

#### MPPF_POS_MASK (0xE0000000)

Mask for position values **MPPF_TOP**, **MPPF_LEFT**, and **MPPF_RIGHT**.

#### MPPF_ALIGN_LEFT (0x02000000)

Default alignment.

#### MPPF_ALIGN_RIGHT (0x04000000)

The pop-up menu should be aligned to the right of the excluded rectangle specified by *prcExclude*.

## Return value

Type: **HRESULT**

Returns **S_OK** if the object implements the pop-up menu as a modeless menu. Otherwise, returns **S_FALSE**, which indicates the end of the implementation for the menu.