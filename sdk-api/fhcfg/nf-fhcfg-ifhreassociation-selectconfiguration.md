# IFhReassociation::SelectConfiguration

## Description

Selects one of the File History configurations discovered on a storage device or network share by the [IFhReassociation::ScanTargetForConfigurations](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhreassociation-scantargetforconfigurations) method for subsequent reassociation. Actual reassociation is performed by the [IFhReassociation::PerformReassociation](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhreassociation-performreassociation) method.

> [!NOTE]
> **IFhReassociation** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `Index` [in]

Zero-based index of a discovered configuration.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

If there is no File History configuration with the specified index, the `HRESULT_FROM_WIN32(ERROR_NOT_FOUND)` error code is returned.

## See also

[FhReassociation](https://learn.microsoft.com/windows/desktop/DevNotes/fhreassociation)

[IFhReassociation](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhreassociation)

[IFhReassociation::PerformReassociation](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhreassociation-performreassociation)

[IFhReassociation::ScanTargetForConfigurations](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhreassociation-scantargetforconfigurations)