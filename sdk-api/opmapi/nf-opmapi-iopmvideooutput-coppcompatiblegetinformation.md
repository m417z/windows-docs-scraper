# IOPMVideoOutput::COPPCompatibleGetInformation

## Description

Sends an Output Protection Manager (OPM) status request to the display driver. Use this method when OPM is emulating Certified Output Protection Manager (COPP).

## Parameters

### `pParameters` [in]

Pointer to an [OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/opmapi/ns-opmapi-opm_configure_parameters) structure. Fill in this structure with data for the status request. For a list of status requests, see [OPM Status Requests](https://learn.microsoft.com/windows/desktop/medfound/opm-status-requests).

### `pRequestedInformation` [out]

Pointer to an [OPM_REQUESTED_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_requested_information) structure. On return, the method fills in this structure with the results of the status request.

## Return value

Returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS** | The OPM object was created with OPM semantics, not COPP semantics. |

## Remarks

This method is equivalent to the **IAMCertifiedOutputProtection::ProtectionStatus** method in COPP.

The [IOPMVideoOutput](https://learn.microsoft.com/windows/desktop/api/opmapi/nn-opmapi-iopmvideooutput) interface supports both OPM semantics and COPP semantics. The **COPPCompatibleGetInformation** method applies only when COPP semantics are used. If the interface pointer was created with OPM semantics, **COPPCompatibleGetInformation** returns ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS. In that case, call [IOPMVideoOutput::GetInformation](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-getinformation) instead.

## See also

[IOPMVideoOutput](https://learn.microsoft.com/windows/desktop/api/opmapi/nn-opmapi-iopmvideooutput)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)