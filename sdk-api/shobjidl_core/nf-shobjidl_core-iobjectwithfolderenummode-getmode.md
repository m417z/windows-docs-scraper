# IObjectWithFolderEnumMode::GetMode

## Description

Retrieves the enumeration mode of the parsed item.

## Parameters

### `pfeMode` [out]

Type: **[FOLDER_ENUM_MODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folder_enum_mode)***

Pointer to a value that, when this method returns successfully, receives one of the [FOLDER_ENUM_MODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folder_enum_mode) values specifying the enumeration mode.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.