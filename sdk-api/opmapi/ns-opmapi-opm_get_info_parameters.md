# OPM_GET_INFO_PARAMETERS structure

## Description

Contains parameters for the [IOPMVideoOutput::GetInformation](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-getinformation) method.

## Members

### `omac`

An [OPM_OMAC](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_omac) structure that contains a message authentication code (MAC) for the data in the rest of the structure.

### `rnRandomNumber`

An [OPM_RANDOM_NUMBER](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_random_number) structure that contains a cryptographically secure 128-bit random number.

### `guidInformation`

A GUID that defines the status request. For more information, see [OPM Status Requests](https://learn.microsoft.com/windows/desktop/medfound/opm-status-requests).

### `ulSequenceNumber`

The status sequence number. The application must keep a running count of status requests. For each request, increment the sequence number by 1.

On the first call to [GetInformation](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-getinformation), set **ulSequenceNumber** equal to the starting status sequence number, which is specified when the application calls [IOPMVideoOutput::FinishInitialization](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-startinitialization). On each subsequent call, increment **ulSequenceNumber** by 1.

Exception: If the status request fails, do not increment the sequence number. Instead, re-use the same number for the next status request.

### `cbParametersSize`

The number of bytes of valid data in the **abParameters** member.

### `abParameters`

The data for the status request. The meaning of the data depends on the request. For more information, see [OPM Status Requests](https://learn.microsoft.com/windows/desktop/medfound/opm-status-requests).

## Remarks

Initialize this structure as follows:

1. Generate a cryptographically secure 128-bit random number and copy it to the **rnRandomNumber** member. Do not re-use this number after calling [GetInformation](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-getinformation).
2. Fill in the remaining structure members, except for the **omac** member.
3. Use the OMAC 1 algorithm to calculate a message authentication code (MAC) for the block of data that appears after the **omac** member (excluding the **omac** member).
4. Copy the MAC to the **omac** member.

## See also

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)