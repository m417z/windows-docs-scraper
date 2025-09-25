# ISensorDriver::OnGetSupportedSensorObjects

## Description

The [ISensorDriver::OnGetSupportedSensorObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-ongetsupportedsensorobjects) method retrieves the list of sensors that the driver provides.

## Parameters

### `ppSensorObjectCollection`

Address of an IPortableDeviceValuesCollection pointer that receives the list of sensors.

## Return value

If the operation succeeds, this method returns S_OK. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## See also

[ISensorDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensordriver)