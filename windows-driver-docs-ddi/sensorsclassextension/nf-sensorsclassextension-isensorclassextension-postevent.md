# ISensorClassExtension::PostEvent

## Description

The [ISensorClassExtension::PostEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensorclassextension-postevent) method raises one or more driver events in the sensor class extension.

## Parameters

### `pwszSensorID`

LPWSTR that contains the ID for the sensor for which the driver is raising the event.

### `pEventCollection`

Pointer to an IPortableDeviceValuesCollection interface that contains the list of events being posted and their associated data.

## Return value

This method returns an HRESULT. Possible values include, but are not limited to, one of the following values.

|Return code|Description|
|--- |--- |
|S_OK|The method succeeded.|
|S_FALSE|The method succeeded, but no client programs are currently subscribed to events. Do not post events when no clients are subscribed.|
|E_INVALIDARG|The event collection was empty.|
|E_POINTER|A required pointer argument was NULL.|
|HRESULT_FROM_WIN32(ERROR_CAN_NOT_COMPLETE)|The class extension is not initialized.|
|HRESULT_FROM_WIN32(ERROR_INTERNAL_DB_CORRUPTION|A serialization error occurred.|
|HRESULT_FROM_WIN32(ERROR_OBJECT_NOT_FOUND)|No client programs are currently subscribed to events. Do not post events when no clients are subscribed.|

## Remarks

The sensor class extension forwards these events to the Sensor API and Location API, which in turn, raise events in client programs.

The collection passed through *pEventCollection* can contain one or more events. Represent each event and its associated data by using one [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) object. Platform-defined **PROPERTYKEY**s for events and data types are defined in sensors.h.

Each [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) object returned by this method must contain a time stamp, as described in [SENSOR_CATEGORY_ALL](https://learn.microsoft.com/windows-hardware/drivers/sensors/sensor-category-all).

The sensor class extension is responsible for freeing any **PROPVARIANT** structures provided by this method.

To specify the event type, use the SENSOR_EVENT_PARAMETER_EVENT_ID **PROPERTYKEY** with the appropriate **GUID** value.

For an example of a class that creates an event thread, see [Raising sensor events](https://learn.microsoft.com/windows-hardware/drivers/sensors/raising-events)

[IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) and [IPortableDeviceValuesCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevaluescollection) are documented in Windows Portable Devices.

**Note** The sensor class extension will call PropVariantClear for PROPVARIANTs that you pass to the sensor class extension.

Raise state change events by calling [ISensorClassExtension::PostStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensorclassextension-poststatechange).

## See also

[ISensorClassExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensorclassextension)