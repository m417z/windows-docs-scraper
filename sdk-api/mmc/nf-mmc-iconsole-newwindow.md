# IConsole::NewWindow

## Description

Creates a new multiple-document interface (MDI) child window rooted at the specified scope item.

## Parameters

### `hScopeItem` [in]

The scope item that forms the root of the new window.

### `lOptions` [in]

Options used to create the new window are listed in the following list.

#### MMC_NW_OPTION_NONE

Display a new window with default window settings. This is the programmatic equivalent to selecting the New Window From Here command from the
**View** context menu.

#### MMC_NW_OPTION_NOSCOPEPANE

Hide the scope pane (Console Tree pane) in the new window.

#### MMC_NW_OPTION_NOTOOLBARS

Hide the standard toolbars in the new window. If the snap-in has custom toolbar buttons and menus, they will appear.

If the snap-in has added its own items to standard menus or toolbars, the addition of those items does not force the standard toolbars or menus that contain them to appear.

#### MMC_NW_OPTION_SHORTTITLE

This option is not supported and its definition exists only for backward compatibility.

#### MMC_NW_OPTION_CUSTOMTITLE

Use the custom title provided by the snap-in. Title bar text contains the display name specified by the item data object implementation of the **CCF_DISPLAY_NAME**.

#### MMC_NW_OPTION_NOPERSIST

Do not save the new window to the .msc file.

## Return value

This method can return one of these values.

## See also

[IConsole](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole)