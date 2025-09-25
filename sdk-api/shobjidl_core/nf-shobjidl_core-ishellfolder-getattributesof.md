# IShellFolder::GetAttributesOf

## Description

Gets the attributes of one or more file or folder objects contained in the object represented by [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder).

## Parameters

### `cidl` [in]

Type: **UINT**

The number of items from which to retrieve attributes.

### `apidl` [in]

Type: **PCUITEMID_CHILD_ARRAY***

The address of an array of pointers to [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures, each of which uniquely identifies an item relative to the parent folder. Each **ITEMIDLIST** structure must contain exactly one [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure followed by a terminating zero.

### `rgfInOut` [in, out]

Type: **SFGAOF***

Pointer to a single **ULONG** value that, on entry, contains the bitwise [SFGAO](https://learn.microsoft.com/windows/desktop/shell/sfgao) attributes that the calling application is requesting. On exit, this value contains the requested attributes that are common to all of the specified items.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To optimize this operation, do not return unspecified flags.

For a folder object, the [SFGAO_BROWSABLE](https://learn.microsoft.com/windows/desktop/shell/sfgao) attribute implies that the client can bind to this object as shown in a general form here.

```cpp
IShellFolder::BindToObject(..., pidl, IID_IShellFolder, &psfItem);

```

The client can then create an [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) on that item through this statement.

```cpp
psfItem->CreateViewObject(..., IID_IShellView,...);

```

The [SFGAO_DROPTARGET](https://learn.microsoft.com/windows/desktop/shell/sfgao) attribute implies that the client can bind to an instance of [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) for this folder by calling [IShellFolder::GetUIObjectOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getuiobjectof) as shown here.

```cpp
IShellFolder::GetUIObjectOf(hwnd, 1, &pidl, IID_IDropTarget, NULL, &pv)

```

The SFGAO_NONENUMERATED attribute indicates an item that is not returned by the enumerator created by the [IShellFolder::EnumObjects](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-enumobjects) method.

## See also

[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)

[IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2)