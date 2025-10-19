# SHARD enumeration

## Description

Indicates the interpretation of the data passed by [SHAddToRecentDocs](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddtorecentdocs) in its *pv* parameter to identify the item whose usage statistics are being tracked.

## Constants

### `SHARD_PIDL`

The *pv* parameter points to a PIDL that identifies the document's file object. PIDLs that identify non-file objects are not accepted.

### `SHARD_PATHA`

The *pv* parameter points to a null-terminated ANSI string with the path and file name of the object.

### `SHARD_PATHW`

The *pv* parameter points to a null-terminated Unicode string with the path and file name of the object.

### `SHARD_APPIDINFO`

**Windows 7 and later**. The *pv* parameter points to a [SHARDAPPIDINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shardappidinfo) structure that pairs an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that identifies the item with an AppUserModelID that associates it with a particular process or application.

### `SHARD_APPIDINFOIDLIST`

**Windows 7 and later**. The *pv* parameter points to a [SHARDAPPIDINFOIDLIST](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shardappidinfoidlist) structure that pairs an absolute PIDL that identifies the item with an AppUserModelID that associates it with a particular process or application.

### `SHARD_LINK`

**Windows 7 and later**. The *pv* parameter is an interface pointer to an [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) object.

### `SHARD_APPIDINFOLINK`

**Windows 7 and later**. The *pv* parameter points to a [SHARDAPPIDINFOLINK](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shardappidinfolink) structure that pairs an [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) that identifies the item with an AppUserModelID that associates it with a particular process or application.

### `SHARD_SHELLITEM`

**Windows 7 and later**. The *pv* parameter is an interface pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object.

## Remarks

Before Windows 7, SHARD_PIDL, SHARD_PATHA, and SHARD_PATHW were defined as individual constants, not as enumeration members.

When providing an [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) through either **SHARD_LINK** or **SHARD_APPIDINFOLINK**, the **IShellLink** instance must provide the following:

* Either a PIDL ([IShellLink::SetIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setidlist)) or the target path ([IShellLink::SetPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setpath) or [IShellLink::SetRelativePath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setrelativepath))
* Command-line arguments ([IShellLink::SetArguments](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setarguments))
* Icon location ([IShellLink::SetIconLocation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-seticonlocation))

The display name must be set through the item's [System.Title (PKEY_Title)](https://learn.microsoft.com/windows/desktop/properties/props-system-title) property. The property can directly hold the display name or it can be an indirect string representation, such as "@shell32.dll,-1324", to use a stored string. An indirect string enables the item name to be displayed in the user's selected language.

Optionally, the description field ([IShellLink::SetDescription](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setdescription)) can be set to provide a custom tooltip for the item in the Jump List.

## See also

[SHAddToRecentDocs](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddtorecentdocs)