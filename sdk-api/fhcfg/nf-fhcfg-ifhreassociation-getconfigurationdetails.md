# IFhReassociation::GetConfigurationDetails

## Description

This method enumerates File History configurations that were discovered on a storage device or network share by the [IFhReassociation::ScanTargetForConfigurations](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhreassociation-scantargetforconfigurations) method and returns additional information about each of the discovered configurations.

> [!NOTE]
> **IFhReassociation** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `Index` [in]

Zero-based index of a discovered configuration.

### `UserName` [out]

On return, contains a pointer to a string allocated with [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) containing the name of the user account under which the configuration was last backed up to.

### `PcName` [out]

On return, contains a pointer to a string allocated with [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) containing the name of the computer from which the configuration was last backed up.

### `BackupTime` [out]

On return, contains the date and time when the configuration was last backed up.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

If there is no File History configuration with the specified index, the `HRESULT_FROM_WIN32(ERROR_NOT_FOUND)` error code is returned.

## Remarks

The caller is responsible for releasing the memory allocated for *UserName* and *PcName* by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) on each of them.

In order to perform reassociation, one of the configurations enumerated by this method must be selected using the [IFhReassociation::SelectConfiguration](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhreassociation-selectconfiguration) method and then the [IFhReassociation::PerformReassociation](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhreassociation-performreassociation) method needs to be called.

## See also

[FhReassociation](https://learn.microsoft.com/windows/desktop/DevNotes/fhreassociation)

[IFhReassociation](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhreassociation)

[IFhReassociation::PerformReassociation](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhreassociation-performreassociation)

[IFhReassociation::ScanTargetForConfigurations](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhreassociation-scantargetforconfigurations)

[IFhReassociation::SelectConfiguration](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhreassociation-selectconfiguration)