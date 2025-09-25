# IBDA_DRIDRMService::GetDRMStatus

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The GetDRMSTatus method returns the current status of the Digital Rights Management (DRM) system for a Media Transform Device (MTD) in a graph under the Protected Broadcast Device Architecture (PBDA).

## Parameters

### `pbstrDrmUuidList` [out]

Address of a variable that gets a comma-delimited string of UUID values that identify the DRM systems supported by the MTD. This method allocates the memory for the variable by calling **SysAllocString** and returns the associated pointer in this parameter. The caller is memory and is responsible for deallocating it by calling **SysFreeString**.

### `DrmUuid` [out]

Address of a variable that gets a GUID identifying the active DRM system for the MTD.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_DRIDRMService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_dridrmservice)