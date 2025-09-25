# _DXGK_FAULT_ERROR_CODE structure

## Description

The **DXGK_FAULT_ERROR_CODE** structure provides a status code for the graphics processing unit (GPU) error reported via a page fault interrupt.

## Members

### `IsDeviceSpecificCode`

When set, this indicates that the GPU error code is specific to the particular vendor. In this case, **DeviceSpecificCode** should be set to a vendor specific error code.

When not set, this indicates that the GPU error can be described via a set of predefined values in [DXGK_GENERAL_ERROR_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgk_general_error_code) enumeration. **GeneralErrorCode** value should be set to the corresponding error code.

### `GeneralErrorCode`

General error code defined by [DXGK_GENERAL_ERROR_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgk_general_error_code).

### `IsDeviceSpecificCodeReservedBit`

Same as **IsDeviceSpecificCode** member above:

When set, this indicates that the GPU error code is specific to the particular vendor. In this case, **DeviceSpecificCode** should be set to a vendor specific error code.

When not set, this indicates that the GPU error can be described via a set of predefined values in [DXGK_GENERAL_ERROR_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgk_general_error_code) enumeration. **GeneralErrorCode** value should be set to the corresponding error code.

### `DeviceSpecificCode`

A device specific error code.

## See also

[DXGK_GENERAL_ERROR_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgk_general_error_code)