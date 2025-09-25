# ISectionList::GetTableIdentifier

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetTableIdentifier** method returns the table identifier (TID) of the packets that this object is receiving.

## Parameters

### `pTableId`

Receives the TID.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | The method succeeded. |

## Remarks

The TID value is set when the object is first initialized.

## See also

[ISectionList Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-isectionlist)