# CfGetPlaceholderStateFromAttributeTag function

## Description

Gets a set of placeholder states based on the *FileAttributes* and *ReparseTag* values of the file.

## Parameters

### `FileAttributes` [in]

The file attribute information.

### `ReparseTag` [in]

The reparse tag information from a file.

## Return value

Can include [CF_PLACEHOLDER_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_placeholder_state); the placeholder state.

## Remarks

The *FileAttributes* and *ReparseTag* can be obtained by listing the directory containing the file or by directly querying *FileAttributeTagInfo* on the file.

The following [CF_PLACEHOLDER_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_placeholder_state) values can be returned:

| Placeholder state | Description |
| **CF_PLACEHOLDER_STATE_NO_STATES** | When returned, the file or directory whose attributes and reparse tag examined by the API is not a cloud files placeholder. |
| **CF_PLACEHOLDER_STATE_PLACEHOLDER** | When set, the file or directory whose attributes and reparse tag examined by the API is a cloud files placeholder. |
| **CF_PLACEHOLDER_STATE_SYNC_ROOT** | When set, the directory is not only a cloud files placeholder directory but also the sync root. |
| **CF_PLACEHOLDER_STATE_ESSENTIAL_PROP_PRESENT** | When set, the file or directory must be a cloud files placeholder, and there exists an essential property in the property store of the file or directory. |
| **CF_PLACEHOLDER_STATE_IN_SYNC** | When set, the file or directory must be a cloud files placeholder, and its content is in sync with the cloud. |
| **CF_PLACEHOLDER_STATE_PARTIAL** | When set, the file or directory must be a cloud files placeholder, and its content is not ready to be consumed by the user application (though it may or may not be fully present locally). An example is a placeholder file whose content has been fully downloaded to the local disk but yet to be validated by a sync provider that has registered the sync root with the hydration modifier **VERIFICATION_REQUIRED**. |
| **CF_PLACEHOLDER_STATE_PARTIALLY_ON_DISK** | When set, the file or directory must be a cloud files placeholder and its content is not fully present locally. When **PARTIALLY_ON_DISK** is set, **PARTIAL** must also be set. |
| **CF_PLACEHOLDER_STATE_INVALID** | This is an invalid state when the API fails to parse the various information of the file or directory. |

## See also

[CF_PLACEHOLDER_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_placeholder_state)