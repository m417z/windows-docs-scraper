# ISensorDriver::OnGetDataFields

## Description

The [ISensorDriver::OnGetDataFields](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-ongetdatafields) method retrieves current sensor data.

## Parameters

### `pClientFile`

 Pointer to an IWDFFile interface that represents the file object for the application requesting the data.

### `pwszSensorID`

LPWSTR that contains the ID for the sensor from which the client application is requesting data.

### `pDataFields`

Pointer to an IPortableDeviceKeyCollection that contains the list of PROPERTYKEY values that represent the data fields being requested.

### `ppDataValues`

Address of an IPortableDeviceValues pointer that receives the requested data.

## Return value

This method returns an HRESULT. Possible values include, but are not limited to, one of the following values.

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NO_DATA)** | The sensor has no data to report. Each of the data fields returned in the ppDataValues parameter is VT_EMPTY. |

## Remarks

Data fields contain sensor-generated data, as opposed to properties, which describe the sensor device. Platform-defined data fields are defined in sensors.h.

Each [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) object returned by this method must contain a time stamp, as described in [SENSOR_CATEGORY_ALL](https://learn.microsoft.com/windows-hardware/drivers/sensors/sensor-category-all).

The sensor class extension is responsible for freeing any **PROPVARIANT** structures returned by this method.

The sensor class extension calls this method only for sensors for which the user has granted permission through Control Panel.

[IPortableDeviceKeyCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicekeycollection) and [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) are documented in Windows Portable Devices.

## See also

[ISensorDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensordriver)