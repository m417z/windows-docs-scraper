# ISensorClassExtension::PostStateChange

## Description

The **ISensorClassExtension::PostStateChange** method notifies the sensor class extension about a change in the operational state of the sensor.

## Parameters

### `pwszSensorID` [in]

**LPWSTR** that contains the ID for the sensor for which the driver is raising the event.

### `state` [in]

[SensorState](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/ne-sensorsclassextension-__midl___midl_itf_windowssensorclassextension_0000_0000_0001) value that indicates the new state.

## Return value

This method returns an HRESULT. Possible values include, but are not limited to, one of the following values.

| Return code | Description |
|--------------------------------------------|-----------------------------------------|
| S_OK | The method succeeded. |
| E_POINTER | A required pointer argument was NULL. |
| HRESULT_FROM_WIN32(ERROR_CAN_NOT_COMPLETE) | The class extension is not initialized. |

## Remarks

Sensor state information is also available through the [SENSOR_PROPERTY_STATE](https://learn.microsoft.com/windows-hardware/drivers/sensors/sensor-properties2) property key.

### Examples

The following example code demonstrates a function that posts a state-changed event.

```cpp
HRESULT PostStateEvent()
{
    // Validate that we have a pointer to the class extension.
    HRESULT hr = (NULL == m_spSensorCXT) ? E_UNEXPECTED : S_OK ;

    if (SUCCEEDED(hr))
    {
        SensorState st;

        // Retrieve the sensor state
        hr = m_pDdi->GetSensorState(&st);

        if (SUCCEEDED(hr))
        {
            // Post the state change event.
            hr = m_spSensorCXT->PostStateChange(g_wszSensorID, st);
        }
    }

    return hr;
}
```

## See also

- [ISensorClassExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensorclassextension)
- [ISensorDriver::OnClientSubscribeToEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-onclientsubscribetoevents)
- [ISensorDriver::OnClientUnsubscribeFromEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-onclientunsubscribefromevents)