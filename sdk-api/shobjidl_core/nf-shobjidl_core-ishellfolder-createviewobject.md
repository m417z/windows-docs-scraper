# IShellFolder::CreateViewObject

## Description

Requests an object that can be used to obtain information from or interact with a folder object.

## Parameters

### `hwndOwner` [in]

Type: **HWND**

A handle to the owner window. If you have implemented a custom folder view object, your folder view window should be created as a child of *hwndOwner*.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*, typically IID_IShellView.

### `ppv` [out]

Type: **void****

When this method returns successfully, contains the interface pointer requested in *riid*. This is typically [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview). See the Remarks section for more details.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To support this request, create an object that exposes the interface indicated by *riid* and return a pointer to that interface.

The primary purpose of this method is to provide Windows Explorer with the folder object's folder view object. Windows Explorer requests a folder view object by setting *riid* to IID_IShellView. The folder view object displays the contents of the folder in the Windows Explorer folder view. The folder view object must be independent of the Shell folder object, because Windows Explorer may call this method more than once to create multiple folder view objects. A new view object must be created each time this method is called. Your folder object can respond in one of two ways to this request. It can:

* Create a custom folder view object and return a pointer to its [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface.
* Create a system folder view object and return a pointer to its [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface.

This method is also used to request objects that expose one of several optional interfaces, including [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) or [IExtractIcon](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iextracticona). In this context, **CreateViewObject** is similar in usage to [IShellFolder::GetUIObjectOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getuiobjectof). However, you call **IShellFolder::GetUIObjectOf** to request an object for one of the items contained by a folder. Call **IShellFolder::CreateViewObject** to request an object for the folder itself. The most commonly requested interfaces are:

* [IQueryInfo](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iqueryinfo)
* [IShellDetails](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishelldetails)
* [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget)

We recommend that you use the **IID_PPV_ARGS** macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.

## See also

[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)

[IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2)