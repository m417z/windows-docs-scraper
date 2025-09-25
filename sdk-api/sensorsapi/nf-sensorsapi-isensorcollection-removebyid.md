# ISensorCollection::RemoveByID

## Description

Removes a sensor from the collection. The sensor to be removed is specified by its ID.

## Parameters

### `sensorID` [in]

The **GUID** of the sensor to remove from the collection.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The specified sensor is not part of the collection. |

## See also

[ISensorCollection](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensorcollection)