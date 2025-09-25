# IOPMVideoOutput::Configure

## Description

Configures a video output. This method sends an Output Protection Manager (OPM) or Certified Output Protection Protocol (COPP) command to the driver.

## Parameters

### `pParameters` [in]

Pointer to an [OPM_CONFIGURE_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/opmapi/ns-opmapi-opm_configure_parameters) structure that contains the command. For a list of OPM commands, see [OPM Commands](https://learn.microsoft.com/windows/desktop/medfound/opm-commands).

### `ulAdditionalParametersSize` [in]

The size of the *pbAdditionalParameters* buffer, in bytes.

### `pbAdditionalParameters` [in]

Pointer to a buffer that contains additional information for the command.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is equivalent to the **IAMCertifiedOutputProtection::ProtectionCommand** method in COPP.

This method supports both OPM semantics and COPP semantics. COPP semantics are supported for backward compatibility; new applications should use OPM semantics.

### OPM Semantics

Some OPM commands require additional configuration information to be passed in the *pbAdditionalParameters* parameter. The *ulAdditionalParametersSize* parameter specifies the size of the additional data.

### COPP Semantics

The *pbAdditionalParameters* parameter must be **NULL**, and *ulAdditionalParametersSize* must be zero.

## See also

[IOPMVideoOutput](https://learn.microsoft.com/windows/desktop/api/opmapi/nn-opmapi-iopmvideooutput)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)