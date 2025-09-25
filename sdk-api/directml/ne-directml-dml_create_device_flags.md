## Description

Supplies additional device creation options to [DMLCreateDevice](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-dmlcreatedevice). Values can be bitwise OR'd together.

## Constants

### `DML_CREATE_DEVICE_FLAG_NONE:0`

No creation options are specified.

### `DML_CREATE_DEVICE_FLAG_DEBUG:0x1`

Enables the DirectML debug layers. To use the debug layers, developer mode must be enabled, and the DirectML debug layers must be installed. If the **DML_CREATE_DEVICE_FLAG_DEBUG** flag is specified and either condition is not met, then [DMLCreateDevice](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-dmlcreatedevice) returns **DXGI_ERROR_SDK_COMPONENT_MISSING**.