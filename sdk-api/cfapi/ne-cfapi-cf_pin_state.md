# CF_PIN_STATE enumeration

## Description

Pin states of a placeholder file or directory.

## Constants

### `CF_PIN_STATE_UNSPECIFIED:0`

The platform can decide freely when the placeholder’s content needs to present or absent locally on the disk.

### `CF_PIN_STATE_PINNED:1`

The sync provider will be notified to fetch the placeholder’s content asynchronously after the pin request is received by the platform. There is no guarantee that the placeholders to be pinned will be fully available locally after a [CfSetPinState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetpinstate) call completes successfully. However, the platform will fail any dehydration request on pinned placeholders.

### `CF_PIN_STATE_UNPINNED:2`

The sync provider will be notified to dehydrate/invalidate the placeholder’s content on-disk asynchronously after the unpin request is received by the platform. There is no guarantee that the placeholders to be unpinned will be fully dehydrated after the API call completes successfully.

### `CF_PIN_STATE_EXCLUDED:3`

the placeholder will never be synced to the cloud by the sync provider. This state can only be set by the sync provider.

### `CF_PIN_STATE_INHERIT:4`

The platform treats it as if the caller performs a move operation on the placeholder and hence re-evaluates the placeholder’s pin state based on its parent’s pin state. See the [Remarks](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_pin_state#-remarks) section for an inheritance table.

## Remarks

|  | Parent | Unspecified | Pinned | Unpinned | Excluded |
| --- | --- | --- | --- | --- | --- |
| File | Unspecified | Unspecified | Pinned | Unspecified | Excluded |
|  | Pinned | Pinned | Pinned | Pinned | Excluded |
|  | Unpinned | Unpinned | Unpinned | Unpinned | Excluded |
|  | Excluded | Unspecified | Pinned | Unspecified | Excluded |
| Directory | Unspecified | Unspecified | Pinned | Unpinned | Excluded |
|  | Pinned | Pinned | Pinned | Pinned | Excluded |
|  | Unpinned | Unpinned | Unpinned | Unpinned | Excluded |
|  | Excluded | Unspecified | Pinned | Unpinned | Excluded |

## See also

[CfSetPinState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetpinstate)