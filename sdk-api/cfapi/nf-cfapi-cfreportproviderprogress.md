# CfReportProviderProgress function

## Description

Allows a sync provider to report progress out-of-band.

## Parameters

### `ConnectionKey` [in]

A connection key representing a communication channel with the sync filter.

### `TransferKey` [in]

An opaque handle to the placeholder.

### `ProviderProgressTotal` [in]

The total progress of the sync provider in response to a fetch data callback.

### `ProviderProgressCompleted` [in]

The completed progress of the sync provider in response to a fetch data callback.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

The filter automatically tracks the progress of hydrations, by tracking ranges that are transferred and/or acknowledged in response to **FETCH_DATA** callbacks. However, if a provider spends the bulk of its time downloading content to a temporary location before beginning to **TRANSFER_DATA** to the filter, the filter would otherwise be unaware that these activities are in any way related to the request.

By calling **CfReportProviderProgress** periodically, the sync provider can report progress to the filter, thereby resetting the 60 second timeout period corresponding to the **CF_CALLBACK_TYPE_FETCH_DATA** callback. This will also make the progress appear smoother.

## See also

[CfReportProviderProgress2](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfreportproviderprogress2)

[CF_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_type)