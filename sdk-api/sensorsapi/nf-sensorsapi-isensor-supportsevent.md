# ISensor::SupportsEvent

## Description

Indicates whether the sensor supports the specified event.

## Parameters

### `eventGuid` [in]

**REFGUID** value specifying the event to search for.

### `pIsSupported` [out]

Address of a **VARIANT_BOOL** that receives a value indicating whether the sensor supports the event.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | NULL was passed in for pIsSupported. |

## See also

[ISensor](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensor)