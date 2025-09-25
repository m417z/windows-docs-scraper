# DXGK_OPM_INTERFACE_3 structure

## Description

The **DXGK_OPM_INTERFACE_3** structure contains pointers to functions in the [Output Protection Manager (OPM) Interface](https://learn.microsoft.com/windows-hardware/drivers/display/supporting-output-protection-manager), which is implemented by the display miniport driver.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

A positive integer that indicates the version number of the OPM interface that is implemented by the display miniport driver. The **Version** member must be set to DXGK_OPM_INTERFACE_VERSION_3, which is defined in *Dispmprt.h*.

### `Context`

A pointer to a private context block. **Context** must be set to **NULL**.

### `InterfaceReference`

A pointer to an interface reference function that is implemented by the display miniport driver. For more information about the operation of an interface reference function, see the Remarks section of the [**INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure.

### `InterfaceDereference`

A pointer to an interface dereference function that is implemented by the display miniport driver. For more information about the operation of an interface dereference function, see the Remarks section of the [**INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure.

### `DxgkDdiOPMGetCertificateSize`

A pointer to the display miniport driver's [**DxgkDdiOPMGetCertificateSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_certificate_size) function.

### `DxgkDdiOPMGetCertificate`

A pointer to the display miniport driver's [**DxgkDdiOPMGetCertificate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_certificate) function.

### `DxgkDdiOPMCreateProtectedOutput`

A pointer to the display miniport driver's [**DxgkDdiOPMCreateProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_create_protected_output) function.

### `DxgkDdiOPMGetRandomNumber`

A pointer to the display miniport driver's [**DxgkDdiOPMGetRandomNumber**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_random_number) function.

### `DxgkDdiOPMSetSigningKeyAndSequenceNumbers`

A pointer to the display miniport driver's [**DxgkDdiOPMSetSigningKeyAndSequenceNumbers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_signing_key_and_sequence_numbers) function.

### `DxgkDdiOPMGetInformation`

A pointer to the display miniport driver's [**DxgkDdiOPMGetInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information) function.

### `DxgkDdiOPMGetCOPPCompatibleInformation`

A pointer to the display miniport driver's [**DxgkDdiOPMGetCOPPCompatibleInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information) function.

### `DxgkDdiOPMConfigureProtectedOutput`

A pointer to the display miniport driver's [**DxgkDdiOPMConfigureProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output) function.

### `DxgkDdiOPMDestroyProtectedOutput`

A pointer to the display miniport driver's [**DxgkDdiOPMDestroyProtectedOutput**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_destroy_protected_output) function.

### `DxgkDdiOPMCreateProtectedOutputNonLocalDisplay`

A pointer to the display miniport driver's [**DxgkDdiOPMCreateProtectedOutputNonLocalDisplay**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_create_protected_output_nonlocal_display) function.

### `DxgkDdiOPMSetSrmList`

A pointer to the display miniport driver's [**DxgkDdiOPMSetSrmList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_srm_list) function.

### `DxgkDdiOPMGetSrmListVersion`

A pointer to the display miniport driver's [**DxgkDdiOPMGetSrmListVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_srm_list_version) function.