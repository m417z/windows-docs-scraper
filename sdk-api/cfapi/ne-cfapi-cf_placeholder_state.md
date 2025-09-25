# CF_PLACEHOLDER_STATE enumeration

## Description

The state of a placeholder file or folder.

## Constants

### `CF_PLACEHOLDER_STATE_NO_STATES:0x00000000`

When returned, the file or directory whose *FileAttributes* and *ReparseTag* examined by the API is not a placeholder.

### `CF_PLACEHOLDER_STATE_PLACEHOLDER:0x00000001`

The file or directory whose *FileAttributes* and *ReparseTag* examined by the API is a placeholder.

### `CF_PLACEHOLDER_STATE_SYNC_ROOT:0x00000002`

The directory is both a placeholder directory as well as the sync root.

### `CF_PLACEHOLDER_STATE_ESSENTIAL_PROP_PRESENT:0x00000004`

The file or directory must be a placeholder and there exists an essential property in the property store of the file or directory.

### `CF_PLACEHOLDER_STATE_IN_SYNC:0x00000008`

The file or directory must be a placeholder and its content in sync with the cloud.

### `CF_PLACEHOLDER_STATE_PARTIAL:0x00000010`

The file or directory must be a placeholder and its content is not ready to be consumed by the user application, though it may or may not be fully present locally. An example is a placeholder file whose content has been fully downloaded to the local disk, but is yet to be validated by a sync provider that has registered the sync root with the hydration modifier **VERIFICATION_REQUIRED**.

### `CF_PLACEHOLDER_STATE_PARTIALLY_ON_DISK:0x00000020`

The file or directory must be a placeholder and its content is not fully present locally. When this is set, **CF_PLACEHOLDER_STATE_PARTIAL** must also be set.

### `CF_PLACEHOLDER_STATE_INVALID:0xffffffff`

This is an invalid state when the API fails to parse the information of the file or directory.

## Remarks

Placeholder state information can be obtained by calling the following functions:

- [CfGetPlaceholderStateFromAttributeTag](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetplaceholderstatefromattributetag)
- [CfGetPlaceholderStateFromFileInfo](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetplaceholderstatefromfileinfo)
- [CfGetPlaceholderStateFromFindData](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetplaceholderstatefromfinddata)

## See also

[CfGetPlaceholderStateFromAttributeTag](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetplaceholderstatefromattributetag)

[CfGetPlaceholderStateFromFileInfo](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetplaceholderstatefromfileinfo)

[CfGetPlaceholderStateFromFindData](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetplaceholderstatefromfinddata)