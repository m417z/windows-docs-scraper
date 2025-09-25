# IDVB_RST::Initialize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **Initialize** method initializes the object using captured table section data. This method is called internally by the [IDvbSiParser::GetRST](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbsiparser-getrst) method, so applications typically should not call it.

## Parameters

### `pSectionList` [in]

Pointer to the [ISectionList](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-isectionlist) interface of the **SectionList** object that contains the section data.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_ALREADY_INITIALIZED** | The object is already initialized. |
| **S_OK** | The method succeeded. |

## See also

[IDVB_RST Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_rst)