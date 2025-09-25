# IDvbSiParser::Initialize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **Initialize** method initializes this object.

## Parameters

### `punkMpeg2Data` [in]

Pointer to the **IUnknown** interface of the [MPEG-2 Sections and Tables Filter](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/mpeg-2-sections-and-tables-filter) or another object that implements the [IMpeg2Data](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-impeg2data) interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | The *punkMpeg2Data* pointer does not expose the **IMpeg2Data** interface. |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | The method succeeded. |

## Remarks

Until this method is called, all other methods on this interface fail.

## See also

[IDvbSiParser Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbsiparser)