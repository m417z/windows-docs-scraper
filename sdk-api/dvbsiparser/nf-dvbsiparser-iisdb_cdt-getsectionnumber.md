# IISDB_CDT::GetSectionNumber

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the section_number field value from
an Integrated Services Digital Broadcasting
(ISDB)
common data table (CDT). The section_number field identifies the position of a subtable within the CDT so that the CDT can be reassembled with its subtables in the proper order.

## Parameters

### `pbVal` [out]

Receives the section_number field value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_CDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_cdt)