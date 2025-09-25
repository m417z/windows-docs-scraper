# ISyncKnowledge2::GetMinimumSupportedVersion

## Description

Gets the minimum supported version of [Microsoft Sync Framework](https://www.microsoft.com/downloads/details.aspx?familyid=A3EE7BC5-A823-4FB4-B152-9E8CE9D5546F&displaylang=en) components that can be used with this object.

## Parameters

### `pVersion` [out]

The minimum supported version of Microsoft Sync Framework components that can be used with this object.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

**Note** This method is used only with synchronization sessions that use [Microsoft Sync Framework](https://www.microsoft.com/downloads/details.aspx?familyid=A3EE7BC5-A823-4FB4-B152-9E8CE9D5546F&displaylang=en) components.

A knowledge object that has a version of **SYNC_SERIALIZATION_VERSION_V2** supports components that are compatible with Sync Framework 1.0 when the knowledge object contains only elements that are compatible with Sync Framework 1.0. In this situation, **GetMinSupportedVersion** returns a version of **SYNC_SERIALIZATION_VERSION_V1**.

For an overview of what is involved in building synchronization providers using [Microsoft Sync Framework](https://www.microsoft.com/downloads/details.aspx?familyid=A3EE7BC5-A823-4FB4-B152-9E8CE9D5546F&displaylang=en), see [Options for Building a Synchronization Provider](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/options-for-building-a-synchronization-provider).

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)

[Options for Building a Synchronization Provider](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/options-for-building-a-synchronization-provider)

[SYNC_SERIALIZATION_VERSION Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-sync_full_enumeration_action)