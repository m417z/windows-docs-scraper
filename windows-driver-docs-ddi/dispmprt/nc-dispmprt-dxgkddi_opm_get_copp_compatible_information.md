# DXGKDDI_OPM_GET_COPP_COMPATIBLE_INFORMATION callback function

## Description

The **DXGKDDI_OPM_GET_COPP_COMPATIBLE_INFORMATION** function retrieves information that is compatible with the Certified Output Protection Protocol (COPP) from the given protected output object.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. Previously, the display miniport driver's [*DxgkDdiAddDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function provided this handle to the DirectX graphics kernel subsystem.

### `ProtectedOutputHandle` [in]

The handle to a protected output object. The [*DxgkDdiOPMCreateProtectedOutput*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_create_protected_output) function creates the protected output object and returns the handle to the object. The protected output object that corresponds to this handle should have COPP semantics.

### `Parameters` [in]

A pointer to a [**DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_copp_compatible_get_info_parameters) structure that contains the type of COPP-compatible information to retrieve from the protected output object whose handle is specified in the **ProtectedOutputHandle** parameter. *DxgkDdiOPMGetCOPPCompatibleInformation* determines if the parameters contain a valid request from the application that indirectly created the protected output object. For more information, see the Remarks section.

### `RequestedInformation` [out]

A pointer to a [**DXGKMDT_OPM_REQUESTED_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_requested_information) structure that receives the protected output object's COPP-compatible information if *DxgkDdiOPMGetCOPPCompatibleInformation* returns successfully.

If *DxgkDdiOPMGetCOPPCompatibleInformation* fails, the value that **RequestedInformation** points to is unchanged.

## Return value

*DxgkDdiOPMGetCOPPCompatibleInformation* returns STATUS_SUCCESS or an *Ntstatus.h* error code.

## Prototype

```cpp
DXGKDDI_OPM_GET_COPP_COMPATIBLE_INFORMATION DxgkDdiOPMGetCOPPCompatibleInformation;

NTSTATUS DxgkDdiOPMGetCOPPCompatibleInformation(
  _In_        PVOID                                            MiniportDeviceContext,
  _In_        HANDLE                                           ProtectedOutputHandle,
  _In_  const PDXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS Parameters,
  _Out_       PDXGKMDT_OPM_REQUESTED_INFORMATION               RequestedInformation
)
{ ... }
```

## Remarks

The DirectX graphics kernel subsystem should call *DxgkDdiOPMGetCOPPCompatibleInformation* only if the output has COPP semantics.

Before the DirectX graphics kernel subsystem passes the protected output handle to the **ProtectedOutputHandle** parameter in a call to *DxgkDdiOPMGetCOPPCompatibleInformation*, the DirectX graphics kernel subsystem always passes the protected output handle to the [*DxgkDdiOPMSetSigningKeyAndSequenceNumbers*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_signing_key_and_sequence_numbers) and [*DxgkDdiOPMGetRandomNumber*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_random_number) functions.

Following are some facts that pertain to *DxgkDdiOPMGetCOPPCompatibleInformation* and that do not pertain to the [*DxgkDdiOPMGetInformation*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information) function:

* The DirectX graphics kernel subsystem can pass a handle to a protected output only with COPP semantics.

* The [**DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_copp_compatible_get_info_parameters) structure that the **Parameters** parameter points to is not signed.

* The DirectX graphics kernel subsystem can pass the DXGKMDT_OPM_GET_ACP_AND_CGMSA_SIGNALING and DXGKMDT_OPM_GET_CONNECTED_HDCP_DEVICE_INFORMATION GUIDs in the **guidInformation** member of DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS.

* The DirectX graphics kernel subsystem cannot pass the DXGKMDT_OPM_GET_CURRENT_HDCP_SRM_VERSION GUID in the **guidInformation** member of DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS.

* The DirectX graphics kernel subsystem can specify DXGKMDT_OPM_PROTECTION_TYPE_COPP_COMPATIBLE_HDCP in the first 4 bytes of the **abParameters** member of DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS along with the DXGKMDT_OPM_GET_VIRTUAL_PROTECTION_LEVEL or DXGKMDT_OPM_GET_ACTUAL_PROTECTION_LEVEL GUID in the **guidInformation** member of DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS.

* The DirectX graphics kernel subsystem cannot specify DXGKMDT_OPM_PROTECTION_TYPE_HDCP in the first 4 bytes of the **abParameters** member of DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS along with the DXGKMDT_OPM_GET_VIRTUAL_PROTECTION_LEVEL or DXGKMDT_OPM_GET_ACTUAL_PROTECTION_LEVEL GUID in the **guidInformation** member of DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS.

The driver must perform the following sequence when its *DxgkDdiOPMGetCOPPCompatibleInformation* function is called.

1. Verify that the protected output handle that was passed to the **ProtectedOutputHandle** parameter of *DxgkDdiOPMGetCOPPCompatibleInformation* has COPP semantics.

2. Retrieve the requested information.

3. Copy the random number that the **rnRandomNumber** member of [**DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_copp_compatible_get_info_parameters) specifies to the **rnRandomNumber** member of the DXGKMDT_OPM_STANDARD_INFORMATION, DXGKMDT_OPM_ACTUAL_OUTPUT_FORMAT, DXGKMDT_OPM_ACP_AND_CGMSA_SIGNALING, or DXGKMDT_OPM_CONNECTED_HDCP_DEVICE_INFORMATION structure. The structure that is used depends on the type of information that the caller requested. The structure is set in the **abRequestedInformation** member of the [**DXGKMDT_OPM_REQUESTED_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_requested_information) structure that the **RequestedInformation** parameter points to.

4. Sign the [**DXGKMDT_OPM_REQUESTED_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_requested_information) structure and place the signature in the **omac** member of DXGKMDT_OPM_REQUESTED_INFORMATION. The AES block cipher and the OMAC-1 signing algorithm should be used to sign the structure. For information about AES, see the [RSA Laboratories](https://www.rsa.com) website. For information about OMAC-1, see the [**DXGKMDT_OPM_OMAC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_omac) reference page.

Initially, the DirectX graphics kernel subsystem calls *DxgkDdiOPMGetCOPPCompatibleInformation* to retrieve information about the output and then calls [*DxgkDdiOPMConfigureProtectedOutput*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output) one or more times to configure the output. Subsequently, the DirectX graphics kernel subsystem calls *DxgkDdiOPMGetCOPPCompatibleInformation* without also calling *DxgkDdiOPMConfigureProtectedOutput*.

*DxgkDdiOPMGetCOPPCompatibleInformation* should be made pageable.

## See also

[*DxgkDdiAddDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[*DxgkDdiOPMConfigureProtectedOutput*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output)

[*DxgkDdiOPMCreateProtectedOutput*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_create_protected_output)

[*DxgkDdiOPMGetInformation*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information)

[*DxgkDdiOPMGetRandomNumber*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_random_number)

[*DxgkDdiOPMSetSigningKeyAndSequenceNumbers*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_signing_key_and_sequence_numbers)

[**DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_copp_compatible_get_info_parameters)

[**DXGKMDT_OPM_OMAC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_omac)

[**DXGKMDT_OPM_REQUESTED_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_requested_information)