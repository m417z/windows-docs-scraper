## Description

**FsRtlGetBypassIoOpenCountPtr** returns a pointer to the count of how many BypassIO opens there are for a given stream.

## Parameters

### `_fo`

The file object on which the query is being made.

## Remarks

When [**FSRTL_ADVANCED_FCB_HEADER.Version**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header) is >= FSRTL_FCB_HEADER_V4, **FsRtlGetBypassIoOpenCountPtr** returns a pointer to the current value of that structure's **BypassIoOpenCount** field. This routine returns NULL for earlier version numbers, which do not have a **BypassIoOpenCount** field.

See [BypassIO for filter drivers](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio) for more information.

## See also

[**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io)