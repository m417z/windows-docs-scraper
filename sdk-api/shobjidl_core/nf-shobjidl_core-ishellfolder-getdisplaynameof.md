# IShellFolder::GetDisplayNameOf

## Description

Retrieves the display name for the specified file object or subfolder.

## Parameters

### `pidl` [in]

Type: **PCUITEMID_CHILD**

PIDL that uniquely identifies the file object or subfolder relative to the parent folder.

### `uFlags` [in]

Type: **[SHGDNF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shgdnf)**

Flags used to request the type of display name to return. For a list of possible values, see the [SHGDNF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shgdnf) enumerated type.

### `pName` [out]

Type: **[STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret)***

When this method returns, contains a pointer to a [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure in which to return the display name. The type of name returned in this structure can be the requested type, but the Shell folder might return a different type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is the caller's responsibility to free resources allocated by this function.

Normally, *pidl* can refer only to items contained by the parent folder. The PIDL must be single-level and contain exactly one [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure followed by a terminating zero. If you want to retrieve the display name of an item that is deeper than one level away from the parent folder, use [SHBindToParent](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shbindtoparent) to bind with the item's immediate parent folder and then pass the item's single-level PIDL to **IShellFolder::GetDisplayNameOf**.

Also, if the [SHGDN_FORPARSING](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shgdnf) flag is set in *uFlags* and the [SHGDN_INFOLDER](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shgdnf) flag is not set, *pidl* can refer to an object at any level below the parent folder in the namespace hierarchy. At one time, *pidl* could be a multilevel PIDL, relative to the parent folder, and could contain multiple [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structures. However, this is no longer supported and *pidl* should now refer only to a single child item.

The simplest way to retrieve the display name from the structure pointed to by *pName* is to pass it to either [StrRetToBuf](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strrettobufa) or [StrRetToStr](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strrettostra). These functions take a [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure and return the name. You can also examine the structure's **uType** member, and retrieve the name from the appropriate member.

The flags specified in *uFlags* are hints about the intended use of the name. They do not guarantee that [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) will return the requested form of the name. If that form is not available, a different one might be returned. In particular, there is no guarantee that the name returned by the [SHGDN_FORPARSING](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shgdnf) flag will be successfully parsed by [IShellFolder::ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-parsedisplayname). There are also some combinations of flags that might cause the **GetDisplayNameOf**/**ParseDisplayName** round trip to not return the original identifier list. This occurrence is exceptional, but you should check to be sure.

**Note** The parsing name that is returned when *uFlags* has the [SHGDN_FORPARSING](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shgdnf) flag set is not necessarily a normal text string. Virtual folders such as My Computer might return a string containing the folder object's GUID in the form "::{GUID}". Developers who implement **IShellFolder::GetDisplayNameOf** are encouraged to return parse names that are as close to the display names as possible, because the end user often needs to type or edit these names.

## See also

[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)

[IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2)