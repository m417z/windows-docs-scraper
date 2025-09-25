# ISyncChangeBatchAdvanced::ConvertFullEnumerationChangeBatchToRegularChangeBatch

## Description

Converts an [ISyncFullEnumerationChangeBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfullenumerationchangebatch) object to an [ISyncChangeBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatch) object.

## Parameters

### `ppChangeBatch` [out]

Returns this change batch object, which is represented as an [ISyncChangeBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatch) object.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_INVALID_OPERATION** | This change batch object is not an [ISyncFullEnumerationChangeBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfullenumerationchangebatch) object. |

## See also

[ISyncChangeBatch Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatch)

[ISyncChangeBatchAdvanced Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchadvanced)

[ISyncFullEnumerationChangeBatch Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncfullenumerationchangebatch)