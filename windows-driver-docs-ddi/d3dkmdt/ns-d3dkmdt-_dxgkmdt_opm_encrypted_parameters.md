# _DXGKMDT_OPM_ENCRYPTED_PARAMETERS structure

## Description

The DXGKMDT_OPM_ENCRYPTED_PARAMETERS structure contains data that is encrypted with the public key from an appropriate certificate.

## Members

### `abEncryptedParameters`

A 256-byte array that comprises data that is encrypted with the public key from an appropriate certificate.

## Remarks

For more information about the certificates and algorithms that are used to encrypt the data in DXGKMDT_OPM_ENCRYPTED_PARAMETERS, see the [DxgkDdiOPMSetSigningKeyAndSequenceNumbers](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_signing_key_and_sequence_numbers) reference page.

## See also

[DxgkDdiOPMSetSigningKeyAndSequenceNumbers](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_signing_key_and_sequence_numbers)