# DXGKDDI_OPM_CONFIGURE_PROTECTED_OUTPUT callback function

## Description

The **DXGKDDI_OPM_CONFIGURE_PROTECTED_OUTPUT** function configures the given protected output object.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. The display miniport driver's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `ProtectedOutputHandle` [in]

The handle to a protected output object. The [**DxgkDdiOPMCreateProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_create_protected_output) function creates the protected output object and returns the handle to the object.

### `Parameters` [in]

A pointer to a [**DXGKMDT_OPM_CONFIGURE_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_configure_parameters) structure that contains parameters that are used to configure the protected output object whose handle is specified in the **ProtectedOutputHandle** parameter.

### `AdditionalParametersSize` [in]

The size, in bytes, of the additional parameters in the buffer that is pointed to by **AdditionalParameters**. For Certified Output Protection Protocol (COPP) emulation, this is 0.

### `AdditionalParameters` [in]

A pointer to a buffer that holds the additional parameters that are used to configure the protected output object whose handle is specified in the **ProtectedOutputHandle** parameter. For COPP emulation, this is NULL. If the **AdditionalParametersSize** parameter is set to 0, **AdditionalParameters** is always set to NULL.

## Return value

**DXGKDDI_OPM_CONFIGURE_PROTECTED_OUTPUT** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function successfully configured the protected output object.|
|STATUS_NO_MEMORY|DxgkDdiOPMConfigureProtectedOutput cannot allocate memory required for it to complete.|

This function might also return other error codes that are defined in *Ntstatus.h*.

## Remarks

The DirectX graphics kernel subsystem calls [**DxgkDdiOPMGetInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information) or [**DxgkDdiOPMGetCOPPCompatibleInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information) to retrieve information about the output and then calls **DXGKDDI_OPM_CONFIGURE_PROTECTED_OUTPUT** one or more times to configure the output.

**DXGKDDI_OPM_CONFIGURE_PROTECTED_OUTPUT** should be made pageable.

## See also

[**DxgkDdiOPMGetCOPPCompatibleInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information)

[**DxgkDdiOPMCreateProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_create_protected_output)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DXGKMDT_OPM_CONFIGURE_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_configure_parameters)

[**DxgkDdiOPMGetInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information)