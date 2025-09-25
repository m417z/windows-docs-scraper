# IDataCollectorCollection::Add

## Description

Adds a data collector to the collection.

## Parameters

### `collector` [in]

An [IDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollector) interface of the data collector to add to this collection.

## Return value

Returns S_OK if successful. The following table shows a possible error value.

| Return code/value | Description |
| --- | --- |
| **PLA_E_DCS_SINGLETON_REQUIRED**<br><br>0x80300102 | The current configuration for the data collector set requires that it contain exactly one data collector. |

## See also

[IDataCollectorCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorcollection)

[IDataCollectorCollection::AddRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorcollection-addrange)

[IDataCollectorCollection::Remove](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorcollection-remove)