# SHARDAPPIDINFOLINK structure

## Description

Contains data used by [SHAddToRecentDocs](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddtorecentdocs) to identify both an item, in this case through an [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka), and the process that it is associated with.

## Members

### `psl`

Type: **[IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka)***

Pointer to an [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) instance that, when launched, opens the item. The shortcut is not added by [SHAddToRecentDocs](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddtorecentdocs) to the user's **Recent** folder ([CSIDL_RECENT](https://learn.microsoft.com/windows/desktop/shell/csidl), [FOLDERID_Recent](https://learn.microsoft.com/windows/desktop/shell/knownfolderid)), but it is added to the **Recent** category in the specified application's Jump List.

### `pszAppID`

Type: **PCWSTR**

The application-defined AppUserModelID associated with the item.

## Remarks

The [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) instance pointed to by **psl** must provide the following:

* Either a pointer to an item identifier list (PIDL) ([IShellLink::SetIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setidlist)) or the target path ([IShellLink::SetPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setpath) or [IShellLink::SetRelativePath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setrelativepath))
* Command-line arguments ([IShellLink::SetArguments](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setarguments))
* Icon location ([IShellLink::SetIconLocation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-seticonlocation))

The display name must be set through the item's [System.Title (PKEY_Title)](https://learn.microsoft.com/windows/desktop/properties/props-system-title) property. The property can directly hold the display name or it can be an indirect string representation, such as "@shell32.dll,-1324", to use a stored string. An indirect string enables the item name to be displayed in the user's selected language.

Optionally, the description field ([IShellLink::SetDescription](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setdescription)) can be set to provide a custom tooltip for the item in the Jump List.

## See also

[Application User Model IDs (AppUserModelIDs)](https://learn.microsoft.com/windows/desktop/shell/appids)

[SHARDAPPIDINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shardappidinfo)

[SHARDAPPIDINFOIDLIST](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shardappidinfoidlist)

[SHAddToRecentDocs](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddtorecentdocs)