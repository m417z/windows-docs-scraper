# IShellLinkW::SetRelativePath

## Description

Sets the relative path to the Shell link object.

## Parameters

### `pszPathRel`

Type: **LPCTSTR**

The address of a buffer that contains the fully-qualified path of the shortcut file, relative to which the shortcut resolution should be performed. It should be a file name, not a folder name.

### `dwReserved`

Type: **DWORD**

Reserved. Set this parameter to zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Clients commonly define a relative link when it may be moved along with its target, causing the absolute path to become invalid. The **SetRelativePath** method can be used to help the link resolution process find its target based on a common path prefix between the target and the relative path. To assist in the resolution process, clients should set the relative path as part of the link creation process.

#### Examples

Consider the following scenario:

* You have a link: c:\MyLink.lnk.
* The link target is c:\MyDocs\MyFile.txt.
* You want to move the link and MyDocs\MyFile.txt to d:\.

You can assist the resolution process by creating the original link with a relative path before the shortcut is saved.

```cpp
::SetRelativePath("c:\MyLink.lnk", NULL);

```

Before the shortcut is resolved, set a new relative path, and the Resolve code will find the file in its new location.

```cpp
::SetRelativePath("d:\MyLink.lnk", NULL);

```

## See also

[IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka)

[IShellLink::Resolve](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-resolve)

[IShellLink::SetIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setidlist)

[IShellLink::SetPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setpath)

**IShellLinkA**

**IShellLinkW**