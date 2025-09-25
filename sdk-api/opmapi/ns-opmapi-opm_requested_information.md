# OPM_REQUESTED_INFORMATION structure

## Description

Contains the result of an [Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager) (OPM) status request.

## Members

### `omac`

An [OPM_OMAC](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_omac) structure that contains a Message Authentication Code (MAC) of the status data. The driver will use AES-based one-key CBC MAC (OMAC) to calculate this value.

### `cbRequestedInformationSize`

The size of the valid data in the **abRequestedInformation** member, in bytes.

### `abRequestedInformation`

A buffer that contains the result of the status request. The meaning of the data depends on the status request. For more information, see [OPM Status Requests](https://learn.microsoft.com/windows/desktop/medfound/opm-status-requests).

## Remarks

The layout of this structure is identical to the [AMCOPPStatusOutput](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-amcoppstatusoutput) structure used in Certified Output Protection Protocol (COPP).

## See also

[IOPMVideoOutput::COPPCompatibleGetInformation](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-coppcompatiblegetinformation)

[IOPMVideoOutput::GetInformation](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-getinformation)

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)