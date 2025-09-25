# PIBIO_SENSOR_QUERY_EXTENDED_INFO_FN callback function

## Description

Called by the Windows Biometric Framework to determine the capabilities and limitations of the biometric sensor component.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `SensorInfo` [out]

Pointer to the [WINBIO_EXTENDED_SENSOR_INFO](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-extended-sensor-info) structure that contains the sensor information returned by this function.

### `SensorInfoSize` [in]

The specified size of the sensor information.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* and *SensorInfo* parameters cannot be **NULL**. |
| **E_INVALIDARG** | The *SensorInfoSize* value is less than the size needed to return the sensor information. |

## Remarks

This method is called once during configuration of the biometric unit.

It will also be called if a client application uses the [WinBioGetProperty](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiogetproperty) function to query the value of the **WINBIO_PROPERTY_EXTENDED_SENSOR_INFO** property.