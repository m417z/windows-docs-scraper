# OPM_ENCRYPTED_INITIALIZATION_PARAMETERS structure

## Description

Contains initialization parameters for an [Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager) (OPM) session.

## Members

### `abEncryptedInitializationParameters`

Pointer to a buffer that contains encrypted initialization parameters for the session. For more information, see [IOPMVideoOutput::FinishInitialization](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-finishinitialization).

## Remarks

The layout of this structure is identical to the [AMCOPPSignature](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-amcoppsignature) structure used in Certified Output Protection Protocol (COPP).

## See also

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)