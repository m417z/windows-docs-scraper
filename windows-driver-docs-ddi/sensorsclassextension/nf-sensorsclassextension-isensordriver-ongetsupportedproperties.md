# ISensorDriver::OnGetSupportedProperties

## Description

The [ISensorDriver::OnGetSupportedProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-ongetsupportedproperties) method retrieves the list of properties that the specified sensor provides.

## Parameters

### `pwszSensorID`

LPWSTR that contains the ID for the sensor from which the client application is requesting the properties list.

### `ppSupportedProperties`

 Address of an IPortableDeviceKeyCollection pointer that receives the list of PROPERTYKEY values that represent the supported properties.

## Return value

If the operation succeeds, this method returns S_OK. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

Properties describe the sensor device, as opposed to data fields, which contain sensor-generated data. Platform-defined properties are defined in sensors.h.

Each [IPortableDeviceKeyCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicekeycollection) object returned in this collection must contain **PROPERTYKEY**s for the required properties, as described in the [Sensor Properties](https://learn.microsoft.com/windows-hardware/drivers/sensors/sensor-properties2) reference section.

[IPortableDeviceKeyCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicekeycollection) is documented in Windows Portable Devices.

## See also

[ISensorDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensordriver)