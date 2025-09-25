# IFaxOutgoingJobs::get_Item

## Description

The **IFaxOutgoingJobs::get_Item** method returns a [IFaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjob) interface from the [IFaxOutgoingJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjobs) interface.

## Parameters

### `vIndex` [in]

Type: **VARIANT**

Variant that specifies the item to retrieve from the collection.

If this parameter is type VT_I2 or VT_I4, the parameter specifies the index of the item to retrieve from the collection. The index is 1-based. If this parameter is type VT_BSTR, the parameter is a job ID that specifies the outbound job to retrieve. Other types are not supported.

### `pFaxOutgoingJob` [out, retval]

Type: **[IFaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjob)****

An address of a pointer that receives a [IFaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjob) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FaxOutgoingJobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjobs)

[IFaxOutgoingJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjobs)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outgoing-jobs)