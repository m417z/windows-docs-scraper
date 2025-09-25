# OPM_GET_CODEC_INFO_PARAMETERS structure

## Description

Contains information for the [OPM_GET_CODEC_INFO](https://learn.microsoft.com/windows/desktop/medfound/opm-get-codec-info) command.

## Members

### `cbVerifier`

The amount of valid data in the **Verifier** array, in bytes.

### `Verifier`

A byte array that contains one of the following:

* The CLSID of the Media Foundation transform (MFT) that represents the hardware codec.
* A null-terminated, wide-character string that contains the symbolic link for the hardware codec. Include the size of the terminating null in the value of the **cbVerifier** member.

## See also

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)