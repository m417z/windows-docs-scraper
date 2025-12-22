# IFsrmReportManager::SetDefaultFilter

## Description

Sets the default report filter value to use with the specified report type.

## Parameters

### `reportType` [in]

The report type. For possible values, see the [FsrmReportType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreporttype) enumeration.

### `filter` [in]

The report filter. For possible values, see the [FsrmReportFilter](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreportfilter) enumeration.

### `filterValue` [in]

The default report filter value.

## Return value

The method returns the following return values.

## Remarks

This value is used if the [IFsrmReport::SetFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreport-setfilter) method was not called to specify a filter value for the report.

Note that each report type supports a specific set of filters. To determine if the filter is valid, call the [IFsrmReportManager::IsFilterValidForReportType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-isfiltervalidforreporttype) method.

The following list lists the variant types associated with the [FsrmReportFilter](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreportfilter) enumeration values used for the *filterValue* parameter.

| Filter type | Variant type |
| --- | --- |
| **FsrmReportFilter_FileGroups** | **VT_BSTR** \| **VT_ARRAY**. Set the **parray** member of the variant. |
| **FsrmReportFilter_MinAgeDays** | **VT_I4**. Set the **lVal** member of the variant. |
| **FsrmReportFilter_MaxAgeDays** | **VT_I4**. Set the **lVal** member of the variant. |
| **FsrmReportFilter_MinQuotaUsage** | **VT_I4**. Set the **lVal** member of the variant. |
| **FsrmReportFilter_MinSize** | **VT_I8**. Set the **llVal** member of the variant. |
| **FsrmReportFilter_NamePattern** | **VT_BSTR**. Set the **bstrVal** member of the variant. |
| **FsrmReportFilter_Owners** | **VT_BSTR** \| **VT_ARRAY**. Set the **parray** member of the variant. |
| **FsrmReportFilter_Property** | **VT_BSTR**. Set the **bstrVal** member of the variant. |

The default filter values are used for report actions.

## See also

[FsrmReportManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmreportmanager)

[IFsrmReportManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportmanager)