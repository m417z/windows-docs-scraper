# IShellFolder::EnumObjects

## Description

Enables a client to determine the contents of a folder by creating an item identifier enumeration object and returning its [IEnumIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumidlist) interface. The methods supported by that interface can then be used to enumerate the folder's contents.

## Parameters

### `hwnd` [in]

Type: **HWND**

If user input is required to perform the enumeration, this window handle should be used by the enumeration object as the parent window to take user input. An example would be a dialog box to ask for a password or prompt the user to insert a CD or floppy disk. If *hwndOwner* is set to **NULL**, the enumerator should not post any messages, and if user input is required, it should silently fail.

### `grfFlags` [in]

Type: **[SHCONTF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf)**

Flags indicating which items to include in the enumeration. For a list of possible values, see the [SHCONTF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf) enumerated type.

### `ppenumIDList` [out]

Type: **[IEnumIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumidlist)****

The address that receives a pointer to the [IEnumIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumidlist) interface of the enumeration object created by this method. If an error occurs or no suitable subobjects are found, *ppenumIDList* is set to **NULL**.

## Return value

Type: **HRESULT**

Returns `S_OK` if successful, or an error value otherwise. Some implementations may also return `S_FALSE`, indicating that there are no children matching the *grfFlags* that were passed in. If `S_FALSE` is returned, *ppenumIDList* is set to `NULL`.

## Remarks

If the method returns S_OK, then *ppenumIDList* receives a pointer to an enumerator. In this case, the calling application must free the returned [IEnumIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumidlist) object by calling its **Release** method.

If the method returns S_FALSE, then the folder contains no suitable subobjects and the pointer specified in *ppenumIDList* is set to **NULL**.

If the method fails, an error value is returned and the pointer specified in *ppenumIDList* is set to **NULL**.

If the folder contains no suitable subobjects, then the **IShellFolder::EnumObjects** method is permitted either to set **ppenumIDList* to **NULL** and return S_FALSE, or to set **ppenumIDList* to an enumerator that produces no objects and return S_OK. Calling applications must be prepared for both success cases.

## See also

[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)

[IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2)

[SHGetDesktopFolder](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetdesktopfolder)