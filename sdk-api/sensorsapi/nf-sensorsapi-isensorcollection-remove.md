# ISensorCollection::Remove

## Description

Removes a sensor from the collection. The sensor is specified by a pointer to the [ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor) interface to be removed.

## Parameters

### `pSensor` [in]

Pointer to the [ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor) interface to remove from the collection.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The specified sensor is not part of the collection. |

## See also

[ISensorCollection](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensorcollection)