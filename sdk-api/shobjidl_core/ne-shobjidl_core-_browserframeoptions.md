# _BROWSERFRAMEOPTIONS enumeration

## Description

Used with method [IBrowserFrameOptions::GetFrameOptions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ibrowserframeoptions-getframeoptions).

## Constants

### `BFO_NONE:0`

Do nothing.

### `BFO_BROWSER_PERSIST_SETTINGS:0x1`

Use the browser stream for this item. (Same window position as IE browser windows.)

### `BFO_RENAME_FOLDER_OPTIONS_TOINTERNET:0x2`

Rename **Folder Options** to **Internet Options** in the Tools or View menu.

### `BFO_BOTH_OPTIONS:0x4`

Keep both **Folder Options** and **Internet Options** in the Tools or View menu.

### `BIF_PREFER_INTERNET_SHORTCUT:0x8`

This namespace extension prefers a .url shortcut over a .lnk shortcut.

### `BFO_BROWSE_NO_IN_NEW_PROCESS:0x10`

Do not use "Browse in New Process" by invoking a shortcut.

### `BFO_ENABLE_HYPERLINK_TRACKING:0x20`

Track display name to determine when hyperlinks should be tagged as previously used.

### `BFO_USE_IE_OFFLINE_SUPPORT:0x40`

Use Internet Explorer's offline support.

### `BFO_SUBSTITUE_INTERNET_START_PAGE:0x80`

Use Start Page support for this namespace extension.

### `BFO_USE_IE_LOGOBANDING:0x100`

Use the Brand block in the Toolbar.

### `BFO_ADD_IE_TOCAPTIONBAR:0x200`

Append `" - Internet Explorer"` to display name in the caption bar.

### `BFO_USE_DIALUP_REF:0x400`

Reference the DialUp reference count while the browser is navigated to this location. This will also enable the ICW and Software update.

### `BFO_USE_IE_TOOLBAR:0x800`

Use the Internet Explorer toolbar.

### `BFO_NO_PARENT_FOLDER_SUPPORT:0x1000`

Disable navigation to parent folders. Used for the button that navigates to parent folder or the View.GoTo.ParentFolder feature.

### `BFO_NO_REOPEN_NEXT_RESTART:0x2000`

Browser windows are not reopened after a reboot of the system, regardless of whether they were open before the reboot. Use the same behavior for the namespace extension.

### `BFO_GO_HOME_PAGE:0x4000`

Add **Home Page** to menu (Go).

### `BFO_PREFER_IEPROCESS:0x8000`

Prefer use of Iexplore.exe over Explorer.exe.

### `BFO_SHOW_NAVIGATION_CANCELLED:0x10000`

If navigation is terminated, show the **Action Canceled** HTML page.

### `BFO_USE_IE_STATUSBAR:0x20000`

Use the persisted Internet Explorer status bar settings.

### `BFO_QUERY_ALL`

Return all values.

## Remarks

These constants are defined in the Shobjidl.h file beginning in Windows Vista.