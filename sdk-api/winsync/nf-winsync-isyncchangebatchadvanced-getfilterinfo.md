# ISyncChangeBatchAdvanced::GetFilterInfo

## Description

Gets the [ISyncFilterInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfilterinfo) that was specified when the change batch was created.

## Parameters

### `ppFilterInfo` [out]

Returns the **ISyncFilterInfo** that was specified when the change batch was created. **NULL** indicates that no filter was specified when the change batch was created.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | No filter was specified when the change batch was created. In this situation, **NULL** is returned in *ppFilterInfo*. |
| **E_POINTER** | Invalid pointer. |

## See also

[ISyncChangeBatchAdvanced Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchadvanced)

[ISyncFilterInfo Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfilterinfo)