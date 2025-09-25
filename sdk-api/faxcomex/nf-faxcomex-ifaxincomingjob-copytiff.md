# IFaxIncomingJob::CopyTiff

## Description

The **CopyTiff** method copies the Tagged Image File Format Class F (TIFF Class F) file associated with the inbound fax job to a file on the local computer.

## Parameters

### `bstrTiffPath` [in]

Type: **BSTR**

Null-terminated string that specifies a fully qualified path and file name on the local computer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farQUERY_JOBS](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjob)

[IFaxIncomingJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingjob)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-incoming-queue)