# IFsrmReportManager::GetReportSizeLimit

## Description

Retrieves the current value of the specified report size limit.

## Parameters

### `limit` [in]

The report size limit which is used to limit the files listed in a report. For possible values, see the [FsrmReportLimit](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreportlimit) enumeration.

### `limitValue` [out]

The limit. The variant type is **VT_I4**. Use the **lVal** member of the variant to access the limit value.

## Return value

The method returns the following return values.

## See also

[FsrmReportManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmreportmanager)

[IFsrmReportManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportmanager)