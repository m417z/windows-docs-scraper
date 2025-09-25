# OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS structure

## Description

Contains parameters for the [IOPMVideoOutput::COPPCompatibleGetInformation](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-coppcompatiblegetinformation) method.

## Members

### `rnRandomNumber`

An [OPM_RANDOM_NUMBER](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_random_number) structure that contains a cryptographically secure 128-bit random number.

### `guidInformation`

A GUID that defines the status request. For more information, see [OPM Status Requests](https://learn.microsoft.com/windows/desktop/medfound/opm-status-requests).

### `ulSequenceNumber`

The sequence number of the status request. The application must keep a running count of status requests. For each request, increment the sequence number by one.

On the first call to [COPPCompatibleGetInformation](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-coppcompatiblegetinformation), set **ulSequenceNumber** equal to the starting sequence number, which is specified when the application calls [IOPMVideoOutput::FinishInitialization](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-startinitialization). On each subsequent call, increment **ulSequenceNumber** by 1.

### `cbParametersSize`

The number of bytes of valid data in the **abParameters** member.

### `abParameters`

The data for the status request. The meaning of the data depends on the request. For more information, see [OPM Status Requests](https://learn.microsoft.com/windows/desktop/medfound/opm-status-requests).

## Remarks

The layout of this structure is identical to the [AMCOPPStatusInput](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-amcoppstatusinput) structure used in COPP.

## See also

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)