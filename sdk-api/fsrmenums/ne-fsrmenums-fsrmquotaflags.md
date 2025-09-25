# FsrmQuotaFlags enumeration

## Description

Defines the options for failing IO operations that violate a quota, enabling or disabling quota
tracking, and providing the status of the quota scan operation.

## Constants

### `FsrmQuotaFlags_Enforce:0x100`

If this flag is set, the server will fail an IO operation that causes the disk space usage to exceed the
quota limit. If this flag is not set, the server will not fail violating IO operations but will still run any
action associated with the quota thresholds.

### `FsrmQuotaFlags_Disable:0x200`

The server will not track quota data for the quota and will not run any action associated with quota
thresholds.

### `FsrmQuotaFlags_StatusIncomplete:0x10000`

The quota is defined on the server but the rebuilding procedure (see
[IFsrmQuotaManager::Scan](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotamanager-scan)) did not start or the scan
failed.

### `FsrmQuotaFlags_StatusRebuilding:0x20000`

The quota is in the process of rebuilding its data from the disk.

## Remarks

You can set the **FsrmQuotaFlags_Enforce** and
**FsrmQuotaFlags_Disable** flags when calling the
[IFsrmQuotaBase::put_QuotaFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotabase-get_quotaflags) method. The
**IFsrmQuotaBase::get_QuotaFlags** method can return
these flags in addition to the **FsrmQuotaFlags_StatusIncomplete** and
**FsrmQuotaFlags_StatusRebuilding** flags.

## See also

[IFsrmQuotaBase::QuotaFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotabase-get_quotaflags)