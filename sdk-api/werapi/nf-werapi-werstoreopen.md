# WerStoreOpen function

## Description

Opens the collection of stored [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) error reports.

## Parameters

### `repStoreType`

The type of report store to open. See Remarks for details.

### `phReportStore`

A pointer to a report store. On a successful call, this will point to the retrieved report store.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error code.

|Return code|Description|
|--- |--- |
|**E_INVALIDARG**|One of the arguments is not a valid value.|

## Remarks

A *storeType* value of **E_STORE_MACHINE_QUEUE** opens the queue of all error reports on the machine that have not yet been sent to Microsoft. A value of **E_STORE_MACHINE_ARCHIVE** opens the store of error reports that have already been sent.

The Windows Error Report (WER) Store is the queue of error reports that have been marked to be sent to Microsoft but have not yet been uploaded. The upload of an error report can be postponed under a number of circumstances. The WerStore functions allow developers to access the stored reports and query the status of each one.

## See also

[WerStoreClose](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoreclose), [WerStoreGetFirstReportKey](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werstoregetfirstreportkey), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)