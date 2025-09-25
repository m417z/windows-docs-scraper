# IDVB_EIT::GetRecordFreeCAMode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetRecordFreeCAMode** method queries whether any of the component streams for an event are scrambled.

## Parameters

### `dwRecordIndex` [in]

Specifies the record number for the event, indexed from zero. Call [IDVB_EIT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvb_eit-getcountofrecords) to get the number of records in the EIT.

### `pfVal` [out]

Pointer to a variable that receives a Boolean value. The value is **TRUE** if the free_CA_mode bit is set, which indicates that one or more streams are scrambled. Otherwise, the value is **FALSE**.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of bounds. |
| **S_OK** | The method succeeded. |

## See also

[IDVB_EIT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_eit)