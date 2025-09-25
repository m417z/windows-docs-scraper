# ISensorDataReport::GetSensorValues

## Description

Retrieves a collection of data field values.

## Parameters

### `pKeys` [in]

Pointer to the [IPortableDeviceKeyCollection](https://learn.microsoft.com/previous-versions//ms739549(v=vs.85)) interface that contains the data fields for which to retrieve values. Set to **NULL** to retrieve values for all supported data fields.

### `ppValues` [out]

Address of an [IPortableDeviceValues](https://learn.microsoft.com/previous-versions//ms740012(v=vs.85)) interface pointer that receives the pointer to the retrieved values.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | A data field was not found. Inspect *ppValues* to determine which values were set to **ERROR_NOT_FOUND**. |
| **E_POINTER** | NULL was passed in for ppValues. |

## Remarks

The **IPortableDeviceKeyCollection** and **IPortableDeviceValues** interfaces are defined by the Windows Portable Devices API.

When this method returns **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)**, one or more of the results contained by the [IPortableDeviceValues](https://learn.microsoft.com/previous-versions//ms740012(v=vs.85)) interface will be set to an **HRESULT** error value.

## See also

[ISensorDataReport](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensordatareport)