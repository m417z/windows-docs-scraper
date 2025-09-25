# PdhBrowseCountersHA function

## Description

Displays a **Browse Counters** dialog box that the user can use to select one or more counters that they want to add to the query.

This function is identical to
the [PdhBrowseCounters](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbrowsecountersa) function, except that it supports the use of handles to data sources.

## Parameters

### `pBrowseDlgData` [in]

A
[PDH_BROWSE_DLG_CONFIG_H](https://learn.microsoft.com/windows/win32/api/pdh/ns-pdh-pdh_browse_dlg_config_ha) structure that specifies the behavior of the dialog box.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes).

## Remarks

Note that the dialog
box can return PDH_DIALOG_CANCELLED if **bSingleCounterPerDialog** is **FALSE** and the user clicks the **Close** button, so your error handling would have to account for this.

> [!NOTE]
> The pdh.h header defines PdhBrowseCountersH as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PDH_BROWSE_DLG_CONFIG_H](https://learn.microsoft.com/windows/win32/api/pdh/ns-pdh-pdh_browse_dlg_config_ha)

[PdhBindInputDataSource](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbindinputdatasourcea)

[PdhEnumMachinesH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenummachinesha)

[PdhEnumObjectItemsH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenumobjectitemsha)

[PdhEnumObjectsH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenumobjectsha)

[PdhExpandWildCardPathH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhexpandwildcardpathha)

[PdhGetDataSourceTimeRangeH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetdatasourcetimerangeh)

[PdhGetDefaultPerfCounterH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetdefaultperfcounterha)

[PdhGetDefaultPerfObjectH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetdefaultperfobjectha)

[PdhOpenQueryH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhopenqueryh)