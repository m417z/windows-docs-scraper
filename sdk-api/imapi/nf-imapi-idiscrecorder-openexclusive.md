# IDiscRecorder::OpenExclusive

## Description

Opens a disc recorder for exclusive access.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

This method blocks file system access to a recorder through applications such as Explorer. The recorder must be opened with this method before it is possible to use the following methods:
[QueryMediaType](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscrecorder-querymediatype),
[Eject](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscrecorder-eject),
[Erase](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscrecorder-erase), and
[Close](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscrecorder-close).

It is important to close the recorder before calling
[IDiscMaster::RecordDisc](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-recorddisc), or it will fail with IMAPI_E_DEVICE_NOTACCESSIBLE. The device is exclusively committed to access through either
[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder) or
[IDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmaster), but not both at the same time. This is to ensure that there is no confusion regarding allowed operations and ownership of a recorder during application control or a burn.

An exclusive lock should be held for as short a time as possible. Requests that come from other operating system components are not queued for later execution. Instead, they are simply failed. This could cause confusion with users who don't think a burn is in progress.

Any time that
**OpenExclusive** is called, it appears to the file system that the disc has been removed. When the corresponding
[Close](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscrecorder-close) call is made, it appears to the file system that the media has reappeared. This may cause auto-run issues.

## See also

[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder)