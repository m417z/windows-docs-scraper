# DXGKMDT_OPM_OMAC structure

## Description

The **DXGKMDT_OPM_OMAC** structure contains a One-key Cipher Block Chaining (CBC)-mode message authentication code (OMAC) for message authenticity.

## Members

### `abOMAC`

A 16-byte array that comprises the OMAC.

## Remarks

For more information about OMAC, see the [OMAC-1 algorithm](https://go.microsoft.com/fwlink/p/?linkid=70417).

The OMAC-1 parameters that OPM and COPP use are:

*E* = AES (Advanced Encryption Standard)

*t* = 128 bits

*K* = The 128-bit key that the display miniport driver receives when [*DxgkDdiOPMSetSigningKeyAndSequenceNumbers*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_signing_key_and_sequence_numbers) is called.

*n* = 128 bits

For information about AES, see the [RSA Laboratories](https://www.rsa.com) website.

## See also

[**DXGKMDT_OPM_CONFIGURE_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_configure_parameters)

[**DXGKMDT_OPM_GET_INFO_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_get_info_parameters)

[**DXGKMDT_OPM_REQUESTED_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_requested_information)