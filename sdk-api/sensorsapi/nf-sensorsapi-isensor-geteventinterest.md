# ISensor::GetEventInterest

## Description

> [!IMPORTANT]
> Use the [UWP Sensor API](https://learn.microsoft.com/windows/uwp/devices-sensors/sensors) instead.
>
> The COM-based Sensor API is deprecated and should not be used in new applications. No additional features or enhancements are planned, and support will be limited.

Retrieves the current event interest settings.

## Parameters

### `ppValues` [out]

Address of a **GUID** pointer that points to an array of sensor event identifiers.

### `pCount` [out]

The count of **GUID**s in the array pointed to by *ppValues*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | NULL was passed in for ppValues or pCount. |

## Remarks

Each sensor event is represented by a **GUID**. This method returns the list of requested events as an array of **GUID**s.

## See also

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)

[SetEventInterest](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nf-sensorsapi-isensor-seteventinterest)