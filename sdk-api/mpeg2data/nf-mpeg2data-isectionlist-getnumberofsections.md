# ISectionList::GetNumberOfSections

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetNumberOfSections** method returns the number of MPEG-2 sections that were received.

## Parameters

### `pCount` [out]

Receives the number of sections.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The request has not completed yet. |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | The method succeeded. |

## See also

[ISectionList Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-isectionlist)