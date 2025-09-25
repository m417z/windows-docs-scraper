# IISDB_LDT::GetRecordDescriptorByIndex

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Returns a descriptor for a specified record
in an Integrated Services Digital Broadcasting (ISDB)
linked description table (LDT).

## Parameters

### `dwRecordIndex` [in]

Specifies the record number, indexed from zero.
Call the [IISDB_LDT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_ldt-getcountofrecords) method to get the number of records in the LDT.

### `dwIndex` [in]

Specifies which descriptor to retrieve, indexed from zero.
Call the [IISDB_LDT::GetRecordCountOfDescriptors](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_ldt-getrecordcountofdescriptors) method
to get the number of descriptors for a particular record.

### `ppDescriptor` [out]

Pointer to the [IGenericDescriptor](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-igenericdescriptor) interface for the object that contains the LDT. Use this interface to retrieve the information in the descriptor.
The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IGenericDescriptor](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-igenericdescriptor)

[IISDB_LDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_ldt)

[IISDB_LDT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_ldt-getcountofrecords)

[IISDB_LDT::GetRecordCountOfDescriptors](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_ldt-getrecordcountofdescriptors)