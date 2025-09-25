# IBDA_TransportStreamInfo::get_PatTableTickCount

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **get_PatTableTickCount** method returns the time when the most recent Program Association Table (PAT) section was received. The time is expressed in terms of the tick count, which is the number of milliseconds that have elapsed since the system was started. For more information, see **GetTickCount** in the Platform SDK documentation.

## Parameters

### `pPatTickCount` [out]

Receives the tick count when the last PAT section was received.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IBDA_TransportStreamInfo Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_transportstreaminfo)