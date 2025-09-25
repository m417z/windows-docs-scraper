# IInstallationAgent::RecordInstallationResult

## Description

Records the result for an update. The result is specified by an [IStringCollection](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-istringcollection) object.

## Parameters

### `installationResultCookie` [in]

A string value that identifies the result cookie.

### `hresult` [in]

The identifier of the result.

### `extendedReportingData` [in]

An [IStringCollection](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-istringcollection) interface that represents a collection of strings that contain the result for an update.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## See also

[IInstallationAgent](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iinstallationagent)