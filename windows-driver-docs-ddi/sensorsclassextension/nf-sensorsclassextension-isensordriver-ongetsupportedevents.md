# ISensorDriver::OnGetSupportedEvents

## Description

The [ISensorDriver::OnGetSupportedEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-ongetsupportedevents) method retrieves the list of events that the specified sensor can raise.

## Parameters

### `pwszSensorID`

LPWSTR that contains the ID for the sensor from which the client application is requesting the events list.

### `ppSupportedEvents`

Address of a GUID pointer that receives the array of supported event IDs. If the driver does not support events, return a buffer containing a single GUID that has its value set to GUID_NULL.

### `pulEventCount`

Address of a ULONG that receives the count of event IDs in the buffer returned through ppSupportedEvents. If the driver does not support events, set this value to zero.

## Return value

If the operation succeeds, this method returns S_OK. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

Event IDs are represented by **GUID**s. Platform-defined events are defined in sensors.h.

You must use CoTaskMemAlloc to create the event ID buffer. The sensor class extension frees this memory.

## See also

[ISensorDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensordriver)