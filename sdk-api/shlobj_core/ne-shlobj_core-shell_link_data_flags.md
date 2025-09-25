# SHELL_LINK_DATA_FLAGS enumeration

## Description

Specifies option settings. Used with [IShellLinkDataList::GetFlags](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinkdatalist-getflags) and [IShellLinkDataList::SetFlags](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinkdatalist-setflags).

## Constants

### `SLDF_DEFAULT:0x00000000`

0x00000000. Default value used when no other flag is explicitly set.

### `SLDF_HAS_ID_LIST:0x00000001`

0x00000001. The Shell link was saved with an ID list.

### `SLDF_HAS_LINK_INFO:0x00000002`

0x00000002. The Shell link was saved with link information to enable distributed tracking. This information is used by .lnk files to locate the target if the targets's path has changed. It includes information such as volume label and serial number, although the specific stored information can change from release to release.

### `SLDF_HAS_NAME:0x00000004`

0x00000004. The link has a name.

### `SLDF_HAS_RELPATH:0x00000008`

0x00000008. The link has a relative path.

### `SLDF_HAS_WORKINGDIR:0x00000010`

0x00000010. The link has a working directory.

### `SLDF_HAS_ARGS:0x00000020`

0x00000020. The link has arguments.

### `SLDF_HAS_ICONLOCATION:0x00000040`

0x00000040. The link has an icon location.

### `SLDF_UNICODE:0x00000080`

0x00000080. Stored strings are Unicode.

### `SLDF_FORCE_NO_LINKINFO:0x00000100`

0x00000100. Prevents the storage of link tracking information. If this flag is set, it is less likely, though not impossible, that a target can be found by the link if that target is moved.

### `SLDF_HAS_EXP_SZ:0x00000200`

0x00000200. The link contains expandable environment strings such as `%windir%`.

### `SLDF_RUN_IN_SEPARATE:0x00000400`

0x00000400. Causes a 16-bit target application to run in a separate Virtual DOS Machine (VDM)/Windows on Windows (WOW).

### `SLDF_HAS_LOGO3ID:0x00000800`

0x00000800. Not supported. Note that as of Windows Vista, this value is no longer defined.

### `SLDF_HAS_DARWINID:0x00001000`

0x00001000. The link is a special Windows Installer link.

### `SLDF_RUNAS_USER:0x00002000`

0x00002000. Causes the target application to run as a different user.

### `SLDF_HAS_EXP_ICON_SZ:0x00004000`

0x00004000. The icon path in the link contains an expandable environment string such as such as `%windir%`.

### `SLDF_NO_PIDL_ALIAS:0x00008000`

0x00008000. Prevents the use of ID list alias mapping when parsing the ID list from the path.

### `SLDF_FORCE_UNCNAME:0x00010000`

0x00010000. Forces the use of the UNC name (a full network resource name), rather than the local name.

### `SLDF_RUN_WITH_SHIMLAYER:0x00020000`

0x00020000. Causes the target of this link to launch with a shim layer active. A shim is an intermediate DLL that facilitates compatibility between otherwise incompatible software services. Shims are typically used to provide version compatibility.

### `SLDF_FORCE_NO_LINKTRACK:0x00040000`

0x00040000. **Introduced in Windows Vista**. Disable object ID distributed tracking information.

### `SLDF_ENABLE_TARGET_METADATA:0x00080000`

0x00080000. **Introduced in Windows Vista**. Enable the caching of target metadata into the link file.

### `SLDF_DISABLE_LINK_PATH_TRACKING:0x00100000`

0x00100000. **Introduced in Windows 7**. Disable shell link tracking.

### `SLDF_DISABLE_KNOWNFOLDER_RELATIVE_TRACKING:0x00200000`

0x00200000. **Introduced in Windows Vista**. Disable known folder tracking information.

### `SLDF_NO_KF_ALIAS:0x00400000`

0x00400000. **Introduced in Windows 7**. Disable known folder alias mapping when loading the IDList during deserialization.

### `SLDF_ALLOW_LINK_TO_LINK:0x00800000`

0x00800000. **Introduced in Windows 7**. Allow link to point to another shell link as long as this does not create cycles.

### `SLDF_UNALIAS_ON_SAVE:0x01000000`

0x01000000. **Introduced in Windows 7**. Remove alias when saving the IDList.

### `SLDF_PREFER_ENVIRONMENT_PATH:0x02000000`

0x02000000. **Introduced in Windows 7**. Recalculate the IDList from the path with the environmental variables at load time, rather than persisting the IDList.

### `SLDF_KEEP_LOCAL_IDLIST_FOR_UNC_TARGET:0x04000000`

0x04000000. **Introduced in Windows 7**. If the target is a UNC location on a local machine, keep the local IDList target in addition to the remote target.

### `SLDF_PERSIST_VOLUME_ID_RELATIVE:0x08000000`

0x08000000. **Introduced in Windows 8**. Persist the target IDlist in its volume-ID-relative form to avoid a dependency on drive letters.

### `SLDF_VALID:0x003FF7FF`

**Introduced in Windows Vista**. A mask for valid [SHELL_LINK_DATA_FLAGS](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ne-shlobj_core-shell_link_data_flags) bits.

| OS | Value |
| --- | --- |
| Windows 8 | 0x0FFFF7FF |
| Windows 7 | 0x07FFF7FF |
| Windows Vista | 0x003FF7FF |

### `SLDF_RESERVED`

Reserved; do not use.