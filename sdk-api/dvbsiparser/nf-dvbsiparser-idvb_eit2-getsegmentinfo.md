# IDVB_EIT2::GetSegmentInfo

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the table identifier and segment number for the current EIT segment.

## Parameters

### `pbTid` [out]

Receives the table identifier.

### `pbSegment` [out]

Receives the segment number.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_UNINITIALIZED** | The [Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvb_eit-initialize) method was not called. |

## See also

[IDVB_EIT2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_eit2)