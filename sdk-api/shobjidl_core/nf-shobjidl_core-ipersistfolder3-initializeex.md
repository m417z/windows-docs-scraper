# IPersistFolder3::InitializeEx

## Description

Initializes a folder and specifies its location in the namespace. If the folder is a shortcut, this method also specifies the location of the target folder.

## Parameters

### `pbc` [in]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

A pointer to an [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) object that provides the bind context. This parameter can be **NULL**.

### `pidlRoot` [in]

Type: **LPCITEMIDLIST**

A pointer to a fully qualified PIDL that specifies the absolute location of a folder or folder shortcut. The calling application is responsible for allocating and freeing this PIDL.

### `ppfti` [in]

Type: **const [PERSIST_FOLDER_TARGET_INFO](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ns-shobjidl_core-persist_folder_target_info)***

A pointer to a [PERSIST_FOLDER_TARGET_INFO](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ns-shobjidl_core-persist_folder_target_info) structure that specifies the location of the target folder and its attributes.

If *ppfti* points to a valid structure, *pidlRoot* represents a folder shortcut.

If *ppfti* is set to **NULL**, *pidlRoot* represents a normal folder. In that case, **InitializeEx** should behave as if [Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipersistfolder-initialize) had been called.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is an extended version of [IPersistFolder::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipersistfolder-initialize). It allows the Shell to initialize folder shortcuts as well as normal folders.