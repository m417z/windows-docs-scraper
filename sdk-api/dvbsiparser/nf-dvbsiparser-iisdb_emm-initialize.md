# IISDB_EMM::Initialize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Initializes the data elements of an Integrated Services
Digital Broadcasting (ISDB) entitlement management message (EMM) table
by using the
list of MPEG-2 EMM sections.

## Parameters

### `pSectionList` [in]

Pointer to the [ISectionList](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-isectionlist) interface for the
MPEG-2 ISDB EMM section list.

### `pMPEGData` [in]

Pointer to the [IMpeg2Data](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-impeg2data) interface of the [MPEG-2 Sections and Tables](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/mpeg-2-sections-and-tables-filter) filter.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_EMM](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_emm)

[IMpeg2Data](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-impeg2data)

[ISectionList](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-isectionlist)