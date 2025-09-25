# ISensorDriver::OnSetProperties

## Description

The **ISensorDriver::OnSetProperties** method specifies values for the specified list of properties.

## Parameters

### `pClientFile` [in]

Pointer to an [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface that represents the file object for the application specifying property values.

### `pwszSensorID` [in]

**LPWSTR** that contains the ID for the sensor for which the client application is specifying property values.

### `pPropertiesToSet` [in]

Pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) interface that contains the list of properties to set and their values.

### `ppResults` [out]

Address of an [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) pointer that receives the list of properties that have been set successfully and their new values. If a property was not set, the new value contains an HRESULT error code.

## Return value

If the operation succeeds, this method returns S_OK. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

Properties describe the sensor device, as opposed to data fields, which contain sensor-generated data. Platform-defined properties are defined in sensors.h.

The list of properties provided through *pPropertiesToSet* is typically a subset of the list you returned through [ISensorDriver::OnGetSupportedProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-ongetsupportedproperties). However, the sensor class extension does not enforce this condition on client applications.

The sensor class extension is responsible for freeing any **PROPVARIANT** structures returned by this method.

[IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) is documented in Windows Portable Devices.

**Note** This method will be called only if the user has enabled the sensor in the **Location and Other Sensors** control panel.

## See also

[ISensorDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensordriver)

[ISensorDriver::OnGetProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-ongetproperties)