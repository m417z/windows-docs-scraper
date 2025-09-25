# ISyncKnowledge::GetVersion

## Description

Gets the version of this knowledge structure.

## Parameters

### `pdwVersion` [out]

Returns the version of this knowledge structure. is one of the values in the [SYNC_SERIALIZATION_VERSION](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-sync_serialization_version) enumeration.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

This value is the version of the knowledge structure itself. When the internal knowledge structure is changed, the version that this method returns will also be changed.

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[SYNC_SERIALIZATION_VERSION Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-sync_serialization_version)