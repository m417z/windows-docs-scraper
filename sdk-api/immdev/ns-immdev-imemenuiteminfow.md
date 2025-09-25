# IMEMENUITEMINFOW structure

## Description

Contains information about IME menu items.

## Members

### `cbSize`

Size, in bytes, of the structure.

### `fType`

Menu item type. This member can have one of the following values.

| Value | Meaning |
| --- | --- |
| IMFT_RADIOCCHECK | Display checked menu items using a radio-button mark instead of a check mark if the **hbmpChecked** member is **NULL**. |
| IMFT_SEPARATOR | Menu item is a separator. A menu item separator appears as a horizontal dividing line. The **hbmpItem** and **szString** members are ignored in this case. |
| IMFT_SUBMENU | Menu item is a submenu. |

### `fState`

Menu item state. This member can have one or more of the following values:

| Value | Meaning |
| --- | --- |
| IMFS_CHECKED | The menu item is checked. For more information, see the description of the **hbmpChecked** member. |
| IMFS_DEFAULT | The menu item is the default. A menu can contain only one default menu item, which is displayed in bold. |
| IMFS_DISABLED | The menu item is disabled and appears dimmed so it cannot be selected. This is equivalent to IMFS_GRAYED. |
| IMFS_ENABLED | The menu item is enabled. This is the default state. |
| IMFS_GRAYED | The menu item is disabled and appears dimmed so it cannot be selected. This is equivalent to IMFS_DISABLED. |
| IMFS_HILITE | The menu item is highlighted. |
| IMFS_UNCHECKED | The menu item is unchecked. For more information about unchecked menu items, see the description of the **hbmpUnchecked** member. |
| IMFS_UNHILITE | The menu item is not highlighted. This is the default state. |

### `wID`

Application-defined 16-bit value that identifies the menu item.

### `hbmpChecked`

Handle to the bitmap to display next to the item if it is checked. If this member is **NULL**, a default bitmap is used. If the IMFT_RADIOCHECK type value is specified, the default bitmap is a bullet. Otherwise, it is a check mark.

### `hbmpUnchecked`

Handle to the bitmap to display next to the item if it is not checked. If this member is **NULL**, no bitmap is used.

### `dwItemData`

Application-defined value associated with the menu item.

### `szString`

Content of the menu item. This is a null-terminated string.

### `hbmpItem`

Handle to a bitmap to display.

## See also

[ImmGetImeMenuItems](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immgetimemenuitemsa)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Structures](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-structures)

## Remarks

> [!NOTE]
> The immdev.h header defines IMEMENUITEMINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).