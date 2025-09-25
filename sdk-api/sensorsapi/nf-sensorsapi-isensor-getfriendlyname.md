# ISensor::GetFriendlyName

## Description

Retrieves the sensor name that is intended to be seen by the user.

## Parameters

### `pFriendlyName` [out]

Address of a **BSTR** that receives the friendly name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The sensor driver did not provide a friendly name value. The value provided through *pFriendlyName* is not valid. |
| **E_POINTER** | NULL was passed in for pFriendlyName. |

## See also

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)