# RoReportFailedDelegate function

## Description

Triggers the Global Error Handler when a delegate failure occurs.

## Parameters

### `punkDelegate` [in]

The delegate to report.

### `pRestrictedErrorInfo` [in]

The error to report. Call the [GetRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-getrestrictederrorinfo) function to get the [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) that represents the error.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.