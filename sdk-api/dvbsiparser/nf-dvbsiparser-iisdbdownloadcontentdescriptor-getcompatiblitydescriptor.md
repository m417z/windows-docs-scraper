# IIsdbDownloadContentDescriptor::GetCompatiblityDescriptor

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets data from the compatibility descriptor in an Integrated Services Digital Broadcasting (ISDB) download content descriptor. The compatibility descriptor specifies a target to be updated by the download.

## Parameters

### `ppbData` [out]

Pointer to a buffer that receives the compatibility descriptor. The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbDownloadContentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbdownloadcontentdescriptor)