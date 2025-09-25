# IISDB_CDT::GetTableDescriptorByIndex

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Returns a specified logo transmission descriptor
from an Integrated Services Digital Broadcasting (ISDB)
common data table (CDT).

## Parameters

### `dwIndex` [in]

Specifies which descriptor to retrieve, indexed from zero. Call the [IISDB_CDT::GetCountOfTableDescriptors](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_cdt-getcountoftabledescriptors) method to get the number of table descriptors.

### `ppDescriptor` [out]

Receives a pointer to the [IGenericDescriptor](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-igenericdescriptor) interface implemented by the descriptor. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IGenericDescriptor](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-igenericdescriptor)

[IISDB_CDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_cdt)