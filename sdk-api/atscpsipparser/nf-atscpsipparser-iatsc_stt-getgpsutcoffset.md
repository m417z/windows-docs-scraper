# IATSC_STT::GetGpsUtcOffset

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetGpsUtcOffset** method returns the current offset between Global Positioning Satellite (GPS) time and Universal Time Coordinated (UTC), in seconds.

## Parameters

### `pbVal` [out]

Receives the GPS_UTC_offset field.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | The method succeeded. |

## Remarks

GPS time is measured in seconds since January 6, 1980, and is not adjusted for leap seconds. To convert GPS time to UTC, which is adjusted for leap seconds, subtract the offset from GPS time.

## See also

[IATSC_STT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iatsc_stt)