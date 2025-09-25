# IFsrmReport::SetFilter

## Description

Sets the current value of the specified report filter.

## Parameters

### `filter` [in]

The filter used to limit the files listed in a report. For possible values, see the
[FsrmReportFilter](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreportfilter) enumeration.

### `filterValue` [in]

The filter value to use for the specified report filter. The filter value cannot contain the following:
slash mark (/), backslash (\\), greater than sign (>), less than sign (<), vertical bar (|), double
quote ("), or colon (:).

## Return value

The method returns the following return values.

## Remarks

The filter value overrides the default value set using the
[IFsrmReportManager::SetDefaultFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-setdefaultfilter)
method.

Note that each report type supports a specific set of filters. To determine if the filter is valid for the
report type, call the
[IFsrmReportManager::IsFilterValidForReportType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-isfiltervalidforreporttype)
method.

The following list lists the variant types associated with the
[FsrmReportFilter](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreportfilter) enumeration values used for the
*filter* parameter.

| Filter type | Variant type |
| --- | --- |
| **FsrmReportFilter_FileGroups** | **VT_BSTR** | **VT_ARRAY**. Set the **parray** member of the variant. |
| **FsrmReportFilter_MinAgeDays** | **VT_I4**. Set the **lVal** member of the variant. |
| **FsrmReportFilter_MaxAgeDays** | **VT_I4**. Set the **lVal** member of the variant. |
| **FsrmReportFilter_MinQuotaUsage** | **VT_I4**. Set the **lVal** member of the variant. |
| **FsrmReportFilter_MinSize** | **VT_I8**. Set the **llVal** member of the variant. |
| **FsrmReportFilter_NamePattern** | **VT_BSTR**. Set the **bstrVal** member of the variant. |
| **FsrmReportFilter_Owners** | **VT_BSTR** | **VT_ARRAY**. Set the **parray** member of the variant. |
| **FsrmReportFilter_Property** | **VT_BSTR**. Set the **bstrVal** member of the variant. |

#### Examples

For an example, see
[Adding a Report to a Job](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/adding-a-report-to-a-job).

## See also

[IFsrmReport](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreport)