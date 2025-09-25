# ILocationReport::GetValue

## Description

[The Win32 Location API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [Windows.Devices.Geolocation](https://learn.microsoft.com/uwp/api/windows.devices.geolocation) API.
]

Retrieves a property value from the location report.

## Parameters

### `pKey` [in]

**REFPROPERTYKEY** that specifies the name of the property to retrieve.

### `pValue` [out]

Address of a **PROPVARIANT** that receives the property value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The properties may be platform defined or manufacturer defined.

Platform-defined **PROPERTYKEY** values for location sensors are defined in the location sensor data types section of sensors.h.

The following is a table of some platform-defined properties that are commonly association with location reports. These property keys have a **fmtid** field equal to **SENSOR_DATA_TYPE_LOCATION_GUID**. Additional properties can be found in sensors.h. If you are implementing your own location report to pass to [SetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-idefaultlocation-setreport), this table indicates which values must be supplied in your report object's implementation of **GetValue**.

| Property key name and type | Description |
| --- | --- |
| SENSOR_DATA_TYPE_LATITUDE **VT_R8** | Degrees latitude where North is positive.<br><br>**Note** A latitude/longitude report object that is passed to [SetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-idefaultlocation-setreport) must provide this value in its implementation of **GetValue**. |
| SENSOR_DATA_TYPE_LONGITUDE **VT_R8** | Degrees longitude where East is positive.<br><br>**Note** A latitude/longitude report object that is passed to [SetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-idefaultlocation-setreport) must provide this value in its implementation of **GetValue**. |
| SENSOR_DATA_TYPE_ALTITUDE_SEALEVEL_METERS **VT_R8** | Altitude with respect to sea level, in meters. |
| SENSOR_DATA_TYPE_ALTITUDE_ELLIPSOID_METERS **VT_R8** | Altitude with respect to the reference ellipsoid, in meters. |
| SENSOR_DATA_TYPE_SPEED_KNOTS **VT_R8** | Speed measured in knots. |
| SENSOR_DATA_TYPE_TRUE_HEADING_DEGREES **VT_R8** | Heading relative to true north in degrees. |
| SENSOR_DATA_TYPE_MAGNETIC_HEADING_DEGREES **VT_R8** | Heading relative to magnetic north in degrees. |
| SENSOR_DATA_TYPE_MAGNETIC_VARIATION **VT_R8** | Magnetic variation. East is positive. |
| SENSOR_DATA_TYPE_ERROR_RADIUS_METERS **VT_R8** | Error radius that indicates accuracy of latitude and longitude in meters.<br><br>**Note** A latitude/longitude report object that is passed to [SetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-idefaultlocation-setreport) must provide this value in its implementation of **GetValue**. |
| SENSOR_DATA_TYPE_ADDRESS1 **VT_LPWSTR** | First line of the address in a civic address report.<br><br>**Note** If a civic address report object that is passed to [SetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-idefaultlocation-setreport) contains this data, it should provide this value in its implementation of **GetValue**. |
| SENSOR_DATA_TYPE_ADDRESS2 **VT_LPWSTR** | Second line of the address in a civic address report.<br><br>**Note** If a civic address report object that is passed to [SetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-idefaultlocation-setreport) contains this data, it should provide this value in its implementation of **GetValue**. |
| SENSOR_DATA_TYPE_CITY **VT_LPWSTR** | City field in a civic address report.<br><br>**Note** If a civic address report object that is passed to [SetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-idefaultlocation-setreport) contains this data, it should provide this value in its implementation of **GetValue**. |
| SENSOR_DATA_TYPE_STATE_PROVINCE **VT_LPWSTR** | State/province field in a civic address report.<br><br>**Note** If a civic address report object that is passed to [SetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-idefaultlocation-setreport) contains this data, it should provide this value in its implementation of **GetValue**. |
| SENSOR_DATA_TYPE_POSTALCODE **VT_LPWSTR** | Postal code field in a civic address report.<br><br>**Note** If a civic address report object that is passed to [SetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-idefaultlocation-setreport) contains this data, it should provide this value in its implementation of **GetValue**. |
| SENSOR_DATA_TYPE_COUNTRY_REGION **VT_LPWSTR** | Country/region code in a civic address report. The value must be a two-letter or three-letter ISO 3166 country code.<br><br>**Note** A civic address report object that is passed to [SetReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nf-locationapi-idefaultlocation-setreport) must provide this value in its implementation of **GetValue**. |
| SENSOR_DATA_TYPE_ALTITUDE_ELLIPSOID_ERROR_METERS **VT_R8** | Altitude error with respect to the reference ellipsoid, in meters. |
| SENSOR_DATA_TYPE_ALTITUDE_SEALEVEL_ERROR_METERS **VT_R8** | Altitude error with respect to sea level, in meters. |

The following is a table of other platform-defined properties that may occur in location reports but are not specific to location. The **fmtid** field of these property keys is **SENSOR_PROPERTY_COMMON_GUID**.

| Property key name and type | Description |
| --- | --- |
| SENSOR_PROPERTY_ACCURACY **VT_UNKNOWN** | IPortableDeviceValues object that contains sensor data type names and their associated accuracies. Accuracy values represent possible variation from true values.<br><br>Accuracy values are expressed by using the same units as the data field, except when otherwise documented. |
| SENSOR_PROPERTY_CHANGE_SENSITIVITY **VT_UNKNOWN** | **IPortableDeviceValues** object that contains sensor data type names and their associated change sensitivity values. Change sensitivity values represent the amount by which the data field must change before the SENSOR_EVENT_DATA_UPDATED event is raised.<br><br>Sensitivity values are expressed by using the same units as the data field, except where otherwise documented. <br><br>For example, a change sensitivity value of 2 for SENSOR_DATA_TYPE_TEMPERATURE_CELSIUS would represent a sensitivity of plus or minus 2 degrees Celsius. |
| SENSOR_PROPERTY_CURRENT_CONNECTION_TYPE **VT_UI4** | [SensorConnectionType](https://learn.microsoft.com/windows/win32/api/sensorsapi/ne-sensorsapi-sensorconnectiontype) value that contains the current connection type. |
| SENSOR_PROPERTY_CURRENT_REPORT_INTERVAL **VT_UI4** | The current elapsed time for sensor data report generation, in milliseconds.<br><br>Setting a value of zero signals the driver to use its default report interval. After receiving a value of zero for this property, a driver must return its default report interval, not zero, when queried.<br><br>Applications can set this value to request a particular report interval, but multiple applications might be using the same driver. Therefore, drivers determine the true report interval that is based on internal logic. For example, the driver might always use the shortest report interval that is requested by the caller. |
| SENSOR_PROPERTY_DESCRIPTION **VT_LPWSTR** | The sensor description string. |
| SENSOR_PROPERTY_DEVICE_PATH **VT_LPWSTR** | Uniquely identifies the device instance with which the sensor is associated. You can use this property to determine whether a device contains multiple sensors.<br><br>Device drivers do not have to support this property because the platform provides this value to applications without querying drivers. |
| SENSOR_PROPERTY_FRIENDLY_NAME **VT_LPWSTR** | The friendly name for the device. |
| SENSOR_PROPERTY_LOCATION_DESIRED_ACCURACY **VT_UI4** | An enumerated value that indicates the type of accuracy handling requested by a client application.**LOCATION_DESIRED_ACCURACY_DEFAULT** (0) indicates that the sensor should use the accuracy for which it can optimize power use and other cost considerations.<br><br>**LOCATION_DESIRED_ACCURACY_HIGH** (1) indicates that the sensor should deliver the most accurate report possible. This includes using services that might charge money, or consuming higher levels of battery power or connection bandwidth. |
| SENSOR_PROPERTY_MANUFACTURER **VT_LPWSTR** | The manufacturer's name. |
| SENSOR_PROPERTY_MIN_REPORT_INTERVAL **VT_UI4** | The minimum elapsed time setting that the hardware supports for sensor data report generation, in milliseconds. |
| SENSOR_PROPERTY_MODEL **VT_LPWSTR** | The sensor model name. |
| SENSOR_PROPERTY_PERSISTENT_UNIQUE_ID **VT_CLSID** | A **GUID** that identifies the sensor. This value must be unique for each sensor on a device, or across devices of the same model as enumerated on the computer. |
| SENSOR_PROPERTY_RANGE_MAXIMUM **VT_UKNOWN** | **IPortableDeviceValues** object that contains sensor data field names and their associated maximum values. |
| SENSOR_PROPERTY_RANGE_MINIMUM **VT_UKNOWN** | **IPortableDeviceValues** object that contains sensor data field names and their associated minimum values. |
| SENSOR_PROPERTY_RESOLUTION **VT_UKNOWN** | **IPortableDeviceValues** object that contains sensor data field names and their associated resolutions. Resolution values represent sensitivity to change in the data field.<br><br>Resolution values are expressed by using the same units as the data field, except when otherwise documented. |
| SENSOR_PROPERTY_SERIAL_NUMBER **VT_LPWSTR** | The sensor serial number. |
| SENSOR_PROPERTY_STATE **VT_UI4** | [SensorState](https://learn.microsoft.com/windows/win32/api/sensorsapi/ne-sensorsapi-sensorstate) value that contains the current sensor state. |
| SENSOR_PROPERTY_TYPE **VT_CLSID** | A **GUID** that identifies the sensor type. Platform-defined sensor types are defined in Sensors.h. |

#### Examples

The following example demonstrates how to call **GetValue** to get a property value. You must include sensors.h to use the constant in the example.

```cpp

PROPVARIANT pv;				
HRESULT hr = spLatLongReport->GetValue(SENSOR_DATA_TYPE_LATITUDE_DEGREES, &pv);
```

The following example shows how to implement **GetValue** in your own report object. This implementation allows the caller to get values for several location report fields. This code requires you to include sensors.h and provarutil.h.

```cpp
STDMETHODIMP CLocationReport::GetValue(REFPROPERTYKEY pKey, PROPVARIANT *pValue)
{
    HRESULT hr = S_OK;

    if (pKey.fmtid == SENSOR_DATA_TYPE_LOCATION_GUID)
    {
        // properties for civic address reports
        if (pKey.pid == SENSOR_DATA_TYPE_ADDRESS1.pid)
        {
            hr = InitPropVariantFromString(m_address1, pValue);
        }
        else if (pKey.pid == SENSOR_DATA_TYPE_ADDRESS2.pid)
        {
            hr = InitPropVariantFromString(m_address2, pValue);
        }
        else if (pKey.pid == SENSOR_DATA_TYPE_CITY.pid)
        {
            hr = InitPropVariantFromString(m_city, pValue);
        }
        else if (pKey.pid == SENSOR_DATA_TYPE_STATE_PROVINCE.pid)
        {
            hr = InitPropVariantFromString(m_stateprovince, pValue);
        }
        else if (pKey.pid == SENSOR_DATA_TYPE_POSTALCODE.pid)
        {
            hr = InitPropVariantFromString(m_postalcode, pValue);
        }
        else if (pKey.pid == SENSOR_DATA_TYPE_COUNTRY_REGION.pid)
        {
            hr = InitPropVariantFromString(m_countryregion, pValue);
        }
        // properties for latitude/longitude reports
        else if (pKey.pid == SENSOR_DATA_TYPE_LATITUDE_DEGREES.pid)
        {
            hr = InitPropVariantFromDouble(m_latitude, pValue);
        }
        else if (pKey.pid == SENSOR_DATA_TYPE_LONGITUDE_DEGREES.pid)
        {
            hr = InitPropVariantFromDouble(m_longitude, pValue);
        }
        else if (pKey.pid == SENSOR_DATA_TYPE_ERROR_RADIUS_METERS.pid)
        {
            hr = InitPropVariantFromDouble(m_errorradius, pValue);
        }
        else
        {
            hr = HRESULT_FROM_WIN32(ERROR_NO_DATA);
            PropVariantInit(pValue);
        }
    }
    return hr;
}

```

## See also

[ILocationReport](https://learn.microsoft.com/windows/desktop/api/locationapi/nn-locationapi-ilocationreport)