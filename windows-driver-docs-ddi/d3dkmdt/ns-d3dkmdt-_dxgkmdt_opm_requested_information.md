# DXGKMDT_OPM_REQUESTED_INFORMATION structure

## Description

The **DXGKMDT_OPM_REQUESTED_INFORMATION** structure contains information that was requested in a call to the [*DxgkDdiOPMGetInformation*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information) or [*DxgkDdiOPMGetCOPPCompatibleInformation*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information) function.

## Members

### `omac`

A [**DXGKMDT_OPM_OMAC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_omac) structure that contains a One-key Cipher Block Chaining (CBC)-mode message authentication code (OMAC) for message authenticity. For more information about OMAC, see the [OMAC-1 algorithm](https://go.microsoft.com/fwlink/p/?linkid=70417). The OMAC-1 parameters that OPM and COPP use are:

*E* = AES (Advanced Encryption Standard)

*t* = 128 bits

*K* = The 128-bit key that the display miniport driver receives when [*DxgkDdiOPMSetSigningKeyAndSequenceNumbers*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_signing_key_and_sequence_numbers) is called.

*n* = 128 bits

For information about AES, see the [RSA Laboratories](https://www.rsa.com) website.

### `cbRequestedInformationSize`

The size, in bytes, of the valid data that the **abRequestedInformation** member points to.

### `abRequestedInformation`

A 4076-byte array that specifies the information that is retrieved from a protected output object.

To return the requested information, the display miniport driver should cast **abRequestedInformation** to one of the following structures, depending on the GUID that was specified in the **guidInformation** member of the [**DXGKMDT_OPM_GET_INFO_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_get_info_parameters) or [**DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_copp_compatible_get_info_parameters) structure that the **Parameters** parameter of [*DxgkDdiOPMGetInformation*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information) or /dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information points to. As an example, the DXGKMDT_OPM_GET_CONNECTED_HDCP_DEVICE_INFORMATION GUID indicates the [**DXGKMDT_OPM_CONNECTED_HDCP_DEVICE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_connected_hdcp_device_information) structure.

| GUID | Structure for retrieved information |
| ---- | ----------------------------------- |
| DXGKMDT_OPM_GET_CONNECTOR_TYPE, DXGKMDT_OPM_GET_SUPPORTED_PROTECTION_TYPES, DXGKMDT_OPM_GET_VIRTUAL_PROTECTION_LEVEL, DXGKMDT_OPM_GET_ACTUAL_PROTECTION_LEVEL, DXGKMDT_OPM_GET_ADAPTER_BUS_TYPE, DXGKMDT_OPM_GET_DVI_CHARACTERISTICS or DXGKMDT_OPM_GET_CURRENT_HDCP_SRM_VERSION | [**DXGKMDT_OPM_STANDARD_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_standard_information) |
| DXGKMDT_OPM_GET_ACTUAL_OUTPUT_FORMAT | [**DXGKMDT_OPM_ACTUAL_OUTPUT_FORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_actual_output_format) |
| DXGKMDT_OPM_GET_OUTPUT_ID | [**DXGKMDT_OPM_OUTPUT_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_output_id). Supported in Windows 7 and later versions. |
| DXGKMDT_OPM_GET_ACP_AND_CGMSA_SIGNALING | [**DXGKMDT_OPM_ACP_AND_CGMSA_SIGNALING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_acp_and_cgmsa_signaling) |
| DXGKMDT_OPM_GET_CONNECTED_HDCP_DEVICE_INFORMATION | [**DXGKMDT_OPM_CONNECTED_HDCP_DEVICE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_connected_hdcp_device_information) |

## See also

[**DXGKMDT_OPM_ACP_AND_CGMSA_SIGNALING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_acp_and_cgmsa_signaling)

[**DXGKMDT_OPM_ACTUAL_OUTPUT_FORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_actual_output_format)

[**DXGKMDT_OPM_CONNECTED_HDCP_DEVICE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_connected_hdcp_device_information)

[**DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_copp_compatible_get_info_parameters)

[**DXGKMDT_OPM_GET_INFO_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_get_info_parameters)

[**DXGKMDT_OPM_OMAC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_omac)

[**DXGKMDT_OPM_OUTPUT_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_output_id)

[**DXGKMDT_OPM_STANDARD_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_standard_information)

[*DxgkDdiOPMGetCOPPCompatibleInformation*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information)

[*DxgkDdiOPMGetInformation*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information)