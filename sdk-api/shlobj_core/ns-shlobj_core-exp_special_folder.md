# EXP_SPECIAL_FOLDER structure

## Description

Holds an extra data block used by [IShellLinkDataList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinkdatalist). It holds special folder information.

## Members

### `cbSize`

Type: **DWORD**

The size of the **EXP_SPECIAL_FOLDER** structure.

### `dwSignature`

Type: **DWORD**

The structure's signature. It should be set to EXP_SPECIAL_FOLDER_SIG.

### `idSpecialFolder`

Type: **DWORD**

The ID of the special folder that the link points into.

### `cbOffset`

Type: **DWORD**

The offset into the saved PIDL.