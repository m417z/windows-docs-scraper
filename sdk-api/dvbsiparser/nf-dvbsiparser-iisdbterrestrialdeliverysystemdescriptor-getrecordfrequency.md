# IIsdbTerrestrialDeliverySystemDescriptor::GetRecordFrequency

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the center frequency from an Integrated Services Digital Broadcasting (ISDB) terrestrial delivery system descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the descriptor to return. To get the number of descriptors, call [IIsdbTerrestrialDeliverySystemDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvbparentalratingdescriptor-getcountofrecords)

### `pdwVal` [out]

Receives the center frequency, in units of 1/7 MHz.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbTerrestrialDeliverySystemDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbterrestrialdeliverysystemdescriptor)