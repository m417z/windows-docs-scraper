# IFaxIncomingJobs::get_Item

## Description

Retrieves a [FaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob) object from the [FaxIncomingJobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjobs) collection.

## Parameters

### `vIndex` [in]

Type: **VARIANT**

**VARIANT** that specifies a value that indicates the item to retrieve from the collection. If this parameter is type **VT_I2** or **VT_I4**, it specifies the index of the item to retrieve. The index is 1-based. If this parameter is type **VT_BSTR**, it specifies a job ID to use to search the collection. Other types are not supported.

### `pFaxIncomingJob` [out, retval]

Type: **[IFaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingjob)****

Receives an indirect pointer to a [FaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFaxIncomingJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingjobs)

[Item](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjobs-item)