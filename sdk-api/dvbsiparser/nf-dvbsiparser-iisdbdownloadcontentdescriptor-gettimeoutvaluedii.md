# IIsdbDownloadContentDescriptor::GetTimeOutValueDII

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the value of the time_out_value_DII field from an Integrated Services Digital Broadcasting (ISDB) download content descriptor. The time_out_value_DII field indicates the recommended timeout value for receiving all sections of the corresponding carousel, in milliseconds.

## Parameters

### `pdwVal` [out]

Receives the recommended timeout value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbDownloadContentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbdownloadcontentdescriptor)