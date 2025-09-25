# PERSIST_FOLDER_TARGET_INFO structure

## Description

Specifies a folder shortcut's target folder and its attributes. This structure is used by [IPersistFolder3::GetFolderTargetInfo](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipersistfolder3-getfoldertargetinfo) and [IPersistFolder3::InitializeEx](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipersistfolder3-initializeex).

## Members

### `pidlTargetFolder`

Type: **PIDLIST_ABSOLUTE**

A fully qualified PIDL of the target folder. Set **pidlTargetFolder** to **NULL** if not specified.

### `szTargetParsingName`

Type: **WCHAR[MAX_PATH]**

A null-terminated Unicode string with the target folder's parsing name. Set **szTargetParsingName** to an empty string if not specified.

### `szNetworkProvider`

Type: **WCHAR[MAX_PATH]**

A null-terminated Unicode string that specifies the type of network provider that will be used when binding to the target folder. The format is the same as that used by the [WNet API](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-). Set **szNetworkProvider** to an empty string if not specified.

### `dwAttributes`

Type: **DWORD**

A **DWORD** value that contains FILE_ATTRIBUTE_* flags as defined in Winnt.h. Set **dwAttributes** to -1 if not specified.

### `csidl`

Type: **int**

The target folder's [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value, if it has one. Set **csidl** to -1 if the target folder does not have a CSIDL. In addition to the CSIDL value, you can also set the following two flags.

#### CSIDL_FLAG_PFTI_TRACKTARGET

Indicates that the target folder should change if the user changes the target folder's underlying CSIDL value.

#### CSIDL_FLAG_CREATE

Indicates that the target folder should be created if it does not already exist.

## Remarks

Any or all of the **pidlTargetFolder**, **szTargetParsingName**, and **csidl** members can be used to specify the target folder's location.

## See also

[IPersistFolder3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipersistfolder3)