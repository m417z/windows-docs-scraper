## Description

Allows a sync provider to report progress out-of-band. Extends [CfReportProviderProgress](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfreportproviderprogress) with additional parameters.

## Parameters

### `ConnectionKey`

A connection key representing a communication channel with the sync filter.

### `TransferKey`

An opaque handle to the placeholder.

### `RequestKey`

Allows the caller to report progress on a specific operation other than hydration.

### `ProviderProgressTotal`

The total progress of the sync provider in response to a fetch data callback.

### `ProviderProgressCompleted`

The completed progress of the sync provider in response to a fetch data callback.

### `TargetSessionId`

Indicates the session at which this progress information is targeted.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

## See also

[CfReportProviderProgress](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfreportproviderprogress)