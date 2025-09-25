# IDiskQuotaUser::GetID

## Description

Retrieves a unique identifier (ID) number for the [DiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser) object. This ID is unique only within the process. It can be used to identify a user object in a set of user objects if the programming language you are using does not support pointers.

## Parameters

### `pulID` [out]

The name strings associated with the disk quota user.

## Return value

This method returns **S_OK**.

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser)