# ISensorDriver::OnGetSupportedDataFields

## Description

The [ISensorDriver::OnGetSupportedDataFields](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-ongetsupporteddatafields) method retrieves the list of data fields that the specified sensor can provide.

## Parameters

### `pwszSensorID`

LPWSTR that contains the ID for the sensor from which the client application is requesting the data fields list.

### `ppSupportedDataFields`

Address of an IPortableDeviceKeyCollection pointer that receives the list of PROPERTYKEY values that represent the supported data fields.

## Return value

If the operation succeeds, this method returns S_OK. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

Data fields contain sensor-generated data, as opposed to properties, which describe the sensor device. Platform-defined data fields are defined in sensors.h.

All drivers must support SENSOR_DATA_TYPE_TIMESTAMP as a required data field.

[IPortableDeviceKeyCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicekeycollection) is documented in Windows Portable Devices.

## See also

[ISensorDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensordriver)