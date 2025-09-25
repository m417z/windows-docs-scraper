# IDvbFrequencyListDescriptor::GetRecordCentreFrequency

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetRecordCentreFrequency** method returns the frequency at a specified index in the frequency list.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the frequency to return. To get the number of frequencies in the descriptor, call [IDvbFrequencyListDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbfrequencylistdescriptor-getcountofrecords).

### `pdwVal` [out]

Receives the centre_frequency field.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IDvbFrequencyListDescriptor Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbfrequencylistdescriptor)