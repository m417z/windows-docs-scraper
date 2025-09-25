# WbioQuerySensorInterface function

## Description

Retrieves a pointer to the [WINBIO_SENSOR_INTERFACE](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_sensor_interface) structure for the sensor adapter.

## Parameters

### `SensorInterface` [out]

Address of a variable that receives a pointer to the [WINBIO_SENSOR_INTERFACE](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_sensor_interface) structure.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| ****E_POINTER**** | The *SensorInterface* parameter cannot be **NULL**. |

## Remarks

The Windows Biometric Framework calls this function after loading a sensor adapter DLL into memory.
Every sensor adapter DLL must therefore implement and export the [WbioQueryEngineInterface](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nf-winbio_adapter-wbioqueryengineinterface) function. The function name is case-sensitive, and its spelling and signature must exactly match the description provided in the Syntax section.

To be visible to the Windows Biometric Framework, the [WbioQueryEngineInterface](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nf-winbio_adapter-wbioqueryengineinterface) function must be named in the EXPORTS section of the export definition linker command file for the DLL.

#### Examples

The following pseudocode shows one possible implementation of this function.

```cpp
HRESULT
WINAPI
WbioQuerySensorInterface(
    __out PWINBIO_SENSOR_INTERFACE *SensorInterface
    )
{
    // g_SensorInterface is a global variable.
    *SensorInterface = &g_SensorInterface;
    return S_OK;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)