# IPersistFolder3::GetFolderTargetInfo

## Description

Provides the location and attributes of a folder shortcut's target folder.

## Parameters

### `ppfti` [out]

Type: **[PERSIST_FOLDER_TARGET_INFO](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ns-shobjidl_core-persist_folder_target_info)***

A pointer to a [PERSIST_FOLDER_TARGET_INFO](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ns-shobjidl_core-persist_folder_target_info) structure used to return the target folder's location and attributes.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [PERSIST_FOLDER_TARGET_INFO](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ns-shobjidl_core-persist_folder_target_info) structure might not be initialized by the caller. **GetFolderTargetInfo** must assign values to all members of the structure before returning it to the caller.