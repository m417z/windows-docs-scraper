# IDiskQuotaControl::ShutdownNameResolution

## Description

The SID-to-name resolver translates user security identifiers (SID) to user names. It runs as a background thread. When a quota control object is destroyed, this thread automatically terminates. The final call to the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method terminates the thread. This is normally all that is required. If you finish with the quota control object, but it is not ready to be destroyed (there are other open reference counts), call this method to terminate the background thread before the object is destroyed.

## Return value

This method returns **S_OK**.

## Remarks

Asynchronous name resolution will also cease after the thread terminates. A subsequent call to the following methods can re-create the SID-to-name resolver thread:

* [IDiskQuotaControl::AddUserName](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotacontrol-addusername)
* [IDiskQuotaControl::AddUserSid](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotacontrol-addusersid)
* [IDiskQuotaControl::CreateEnumUsers](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotacontrol-createenumusers)
* [IDiskQuotaControl::FindUserName](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotacontrol-findusername)
* [IDiskQuotaControl::FindUserSid](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotacontrol-findusersid)

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)