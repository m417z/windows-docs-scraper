# WerFreeString function

## Description

Frees up the memory used to store a [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) key string.

## Parameters

### `pwszStr`

The string to be freed (value set to **NULL**).

### Remarks

This method should be called after each successive call to [WerStoreGetFirstReportKey](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoregetfirstreportkey) or [WerStoreGetNextReportKey](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoregetnextreportkey), once the particular report key string has been used and is no longer needed.

## See also

[WerStoreGetFirstReportKey](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoregetfirstreportkey), [WerStoreGetNextReportKey](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoregetnextreportkey), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)