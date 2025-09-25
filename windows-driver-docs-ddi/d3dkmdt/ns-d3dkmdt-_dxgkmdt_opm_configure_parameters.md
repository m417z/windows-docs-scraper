# DXGKMDT_OPM_CONFIGURE_PARAMETERS structure

## Description

The **DXGKMDT_OPM_CONFIGURE_PARAMETERS** structure contains parameters that are used to configure a protected output object in a call to the [*DxgkDdiOPMConfigureProtectedOutput*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output) function.

## Members

### `omac`

A [**DXGKMDT_OPM_OMAC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_omac) structure that contains a One-key Cipher Block Chaining (CBC)-mode message authentication code (OMAC) for message authenticity. For more information about OMAC, see the [OMAC-1 algorithm](https://go.microsoft.com/fwlink/p/?linkid=70417). The OMAC-1 parameters that OPM and COPP use are:

*E* = AES (Advanced Encryption Standard)

*t* = 128 bits

*K* = The 128-bit key the display miniport driver receives when [*DxgkDdiOPMSetSigningKeyAndSequenceNumbers*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_signing_key_and_sequence_numbers) is called.

*n* = 128 bits

For information about AES, see the [RSA Laboratories](https://www.rsa.com) website.

### `guidSetting`

The GUID that is used to configure the protected output object. **guidSetting** can be set to one of the following GUIDs:

* DXGKMDT_OPM_SET_PROTECTION_LEVEL
* DXGKMDT_OPM_SET_ACP_AND_CGMSA_SIGNALING
* DXGKMDT_OPM_SET_HDCP_SRM
* DXGKMDT_OPM_SET_PROTECTION_LEVEL_ACCORDING_TO_CSS_DVD. Supported in Windows 7 and later versions.

### `ulSequenceNumber`

A sequence number. For the [*DxgkDdiOPMConfigureProtectedOutput*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output) function to process a configure request, the value in **ulSequenceNumber** must match the current 4-byte sequence number that the display miniport driver stores. If a match is not detected, *DxgkDdiOPMConfigureProtectedOutput* returns an error code. If a match is detected, *DxgkDdiOPMConfigureProtectedOutput* increments the stored sequence number before returning. The initial 4-byte sequence number is part of the 256-byte array that the *EncryptedParameters* parameter of the [*DxgkDdiOPMSetSigningKeyAndSequenceNumbers*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_signing_key_and_sequence_numbers) function points to.

### `cbParametersSize`

The size, in bytes, of the valid configuration data that the **abParameters** member points to.

### `abParameters`

A 4056-byte array that specifies how to configure the protected output object.

The **abParameters** parameter is cast to one of the following structures that contains the configuration information, depending on the GUID that is specified in the **guidSetting** member of DXGKMDT_OPM_CONFIGURE_PARAMETERS that the *Parameters* parameter of [*DxgkDdiOPMConfigureProtectedOutput*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output) points to.

These are possible GUIDs and structures for configuration information:

| GUID | Structure for retrieved information |
| ---- | ----------------------------------- |
| DXGKMDT_OPM_SET_PROTECTION_LEVEL or DXGKMDT_OPM_SET_PROTECTION_LEVEL_ACCORDING_TO_CSS_DVD | [**DXGKMDT_OPM_SET_PROTECTION_LEVEL_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_set_protection_level_parameters) |
| DXGKMDT_OPM_SET_ACP_AND_CGMSA_SIGNALING | [**DXGKMDT_OPM_SET_ACP_AND_CGMSA_SIGNALING_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_set_acp_and_cgmsa_signaling_parameters) |
| DXGKMDT_OPM_SET_HDCP_SRM | [**DXGKMDT_OPM_SET_HDCP_SRM_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_set_hdcp_srm_parameters) |

## See also

[**DXGKMDT_OPM_OMAC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_omac)

[**DXGKMDT_OPM_SET_ACP_AND_CGMSA_SIGNALING_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_set_acp_and_cgmsa_signaling_parameters)

[**DXGKMDT_OPM_SET_HDCP_SRM_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_set_hdcp_srm_parameters)

[**DXGKMDT_OPM_SET_PROTECTION_LEVEL_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_set_protection_level_parameters)

[*DxgkDdiOPMConfigureProtectedOutput*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output)

[*DxgkDdiOPMSetSigningKeyAndSequenceNumbers*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_signing_key_and_sequence_numbers)