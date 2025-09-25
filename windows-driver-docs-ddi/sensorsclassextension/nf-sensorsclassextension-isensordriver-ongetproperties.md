# ISensorDriver::OnGetProperties

## Description

The [ISensorDriver::OnGetProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-ongetproperties) method retrieves values for the specified properties from the specified sensor.

## Parameters

### `pClientFile`

 Pointer to an IWDFFile interface that represents the file object for the application requesting property values.

### `pwszSensorID`

LPWSTR that contains the ID for the sensor from which the client application is requesting property values.

### `pProperties`

 Pointer to an IPortableDeviceKeyCollection that contains the list of PROPERTYKEY values that represent the properties being requested.

### `ppPropertyValues`

Address of an IPortableDeviceValues pointer that receives the requested property values.

## Return value

If the operation succeeds, this method returns S_OK. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

Properties describe the sensor device, as opposed to data fields, which contain sensor-generated data. Platform-defined properties are defined in sensors.h.

Applications can access some sensor property information before the user grants permission for the sensor. These items are limited to the following IDs defined in sensors.h:

* Any **PROPERTYKEY** that starts with "SENSOR_PROPERTY_".
* Any category **GUID** that starts with "SENSOR_CATEGORY_".

Each [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) object returned in this collection must contain values for the required properties, as described in the [Sensor Properties](https://learn.microsoft.com/windows-hardware/drivers/sensors/sensor-properties2) reference section.

The sensor class extension is responsible for freeing any **PROPVARIANT** structures returned by this method.

Sensor properties must not contain information that can be used to identify the user. For more information about user privacy, see [Privacy and Security in the Sensor and Location Platform](https://learn.microsoft.com/windows-hardware/drivers/gnss/privacy-and-security-in-the-sensor-and-location-platform).

[IPortableDeviceKeyCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicekeycollection) and [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) are documented in Windows Portable Devices.

## See also

[ISensorDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensordriver)