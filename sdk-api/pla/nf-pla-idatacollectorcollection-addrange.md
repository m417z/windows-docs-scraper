# IDataCollectorCollection::AddRange

## Description

Adds one or more data collectors to the collection.

## Parameters

### `collectors` [in]

An [IDataCollectorCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorcollection) interface to a collection of one or more data collectors to add to this collection.

## Return value

Returns S_OK if successful. The following table shows a possible error value.

| Return code/value | Description |
| --- | --- |
| **PLA_E_DCS_SINGLETON_REQUIRED**<br><br>0x80300102 | The current configuration for the data collector set requires that it contain exactly one data collector. |

## See also

[IDataCollectorCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorcollection)

[IDataCollectorCollection::Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorcollection-add)

[IDataCollectorCollection::Remove](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorcollection-remove)