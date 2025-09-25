# IFaxIncomingQueue::GetJob

## Description

The **GetJob** method returns an incoming fax job in the job queue according to its ID.

## Parameters

### `bstrJobId` [in]

Type: **BSTR**

Specifies the job ID.

### `pFaxIncomingJob` [out, retval]

Type: **[IFaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingjob)****

A [FaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farQUERY_JOBS](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) and [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access rights.

## See also

[FaxIncomingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingqueue)

[IFaxIncomingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingqueue)