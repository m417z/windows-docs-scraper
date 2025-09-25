# PdhBrowseCountersW function

## Description

Displays a **Browse Counters** dialog box that the user can use to select one or more counters that they want to add to the query.

To use handles to data sources, use the
[PdhBrowseCountersH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbrowsecountersha) function.

## Parameters

### `pBrowseDlgData` [in]

A
[PDH_BROWSE_DLG_CONFIG](https://learn.microsoft.com/windows/win32/api/pdh/ns-pdh-pdh_browse_dlg_config_a) structure that specifies the behavior of the dialog box.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes).

## Remarks

Note that the dialog
box can return PDH_DIALOG_CANCELLED if **bSingleCounterPerDialog** is **FALSE** and the user clicks the **Close** button, so your error handling would have to account for this.

For information on using this function, see [Browsing Counters](https://learn.microsoft.com/windows/desktop/PerfCtrs/browsing-counters).

#### Examples

For an example, see
[Browsing Performance Counters](https://learn.microsoft.com/windows/desktop/PerfCtrs/browsing-performance-counters).

> [!NOTE]
> The pdh.h header defines PdhBrowseCounters as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CounterPathCallBack](https://learn.microsoft.com/windows/desktop/api/pdh/nc-pdh-counterpathcallback)

[PDH_BROWSE_DLG_CONFIG](https://learn.microsoft.com/windows/win32/api/pdh/ns-pdh-pdh_browse_dlg_config_a)

[PdhBrowseCountersH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbrowsecountersha)