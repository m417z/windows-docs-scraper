# IDiscRecorder::GetBasePnPID

## Description

Retrieves a base PnP string that can be used to consistently identify a specific class of device by make and model. The string can be used by applications to customize their behavior according to the specific recorder type.

## Parameters

### `pbstrBasePnPID` [out]

Base PnP ID string. The string is a concatenation of a recorder's manufacturer, product ID, and revision information (if available).

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder)