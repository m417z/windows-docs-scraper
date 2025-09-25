# WINBIO_PIPELINE structure

## Description

The **WINBIO_PIPELINE** structure contains shared context information used by the sensor, engine, and storage adapter components in a single biometric unit.

## Members

### `SensorHandle`

File handle to the sensor device associated with the biometric unit. Adapters should treat this as a read-only field.

### `EngineHandle`

File handle to the dedicated hardware matching engine, if one is present. This is modified only by the engine adapter. It is read by the Windows Biometric Framework.

### `StorageHandle`

File handle to the template storage database. This is read by the Windows Biometric Framework, but it is modified only by the storage adapter.

### `SensorInterface`

Pointer to the [WINBIO_SENSOR_INTERFACE](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_sensor_interface) structure for the biometric unit. Adapters should ignore this field.

### `EngineInterface`

Pointer to the [WINBIO_ENGINE_INTERFACE](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_engine_interface) structure for the biometric unit. Adapters should ignore this field.

### `StorageInterface`

Pointer to the [WINBIO_STORAGE_INTERFACE](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_storage_interface) structure for the biometric unit. Adapters should ignore this field.

### `SensorContext`

Pointer to a private data structure defined by the sensor adapter. This pointer and the structure contents are managed by the sensor adapter and are never accessed by the Windows Biometric Framework.

### `EngineContext`

Pointer to a private data structure defined by the engine adapter. This pointer and the structure contents are managed by the engine adapter and are never accessed by the Windows Biometric Framework.

### `StorageContext`

Pointer to a private data structure defined by the storage adapter. This pointer and the structure contents are managed by the storage adapter and are never accessed by the Windows Biometric Framework.

### `FrameworkInterface`

## Remarks

Each biometric unit has its own unique **WINBIO_PIPELINE** structure to maintain the current processing state of operations performed by the biometric unit. The Windows Biometric Framework automatically passes the address of the pipeline structure to each adapter in the component stack. Adapters use this pipeline pointer to access their own private context data and to call functions in lower levels of the component stack.

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[Plug-in Structures](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-structures)