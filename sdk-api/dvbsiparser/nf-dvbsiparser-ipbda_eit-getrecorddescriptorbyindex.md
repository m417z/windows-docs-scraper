# IPBDA_EIT::GetRecordDescriptorByIndex

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Retrieves a descriptor for a specified record in an event information table (EIT) in a Protected Broadcast Device Architecture (PBDA) transport stream.

## Parameters

### `dwRecordIndex` [in]

Specifies the service record number, indexed from zero.
Call the [IPBDA_EIT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-ipbda_eit-getcountofrecords) method to get the number of records in the EIT.

### `dwIndex` [in]

Specifies the descriptor to retrieve, indexed from zero. Call the [IPBDA_EIT::GetRecordCountOfDescriptors](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-ipbda_eit-getrecordcountofdescriptors) method to get the number of descriptors for a particular record.

### `ppDescriptor` [out]

Address of a variable that receives an [IGenericDescriptor](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-igenericdescriptor) interface pointer. Use this interface to retrieve the information in the descriptor. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IGenericDescriptor](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-igenericdescriptor)

[IPBDA_EIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-ipbda_eit)