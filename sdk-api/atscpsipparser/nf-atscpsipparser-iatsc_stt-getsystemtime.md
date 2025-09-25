# IATSC_STT::GetSystemTime

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetSystemTime** method returns the current system time.

## Parameters

### `pmdtSystemTime` [out]

Pointer to an [MPEG_DATE_AND_TIME](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpeg_date_and_time) structure allocated by the caller. The method fills the structure with the system time.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | The method succeeded. |

## See also

[IATSC_STT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iatsc_stt)