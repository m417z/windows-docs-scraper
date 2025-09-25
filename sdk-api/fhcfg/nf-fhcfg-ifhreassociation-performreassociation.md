# IFhReassociation::PerformReassociation

## Description

This method re-establishes relationship between the current user and the configuration selected previously via the [IFhReassociation::SelectConfiguration](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhreassociation-selectconfiguration) method and prepares the target device for accepting backup data from the current computer.

> [!NOTE]
> **IFhReassociation** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `OverwriteIfExists` [in]

This parameter specifies how to handle the current File History configuration, if it already exists.

If this parameter is set to **FALSE** and File History is already configured for the current user, this method fails with the **FHCFG_E_CONFIG_ALREADY_EXISTS** error code and backups continue to be performed to the already configured target device.

If this parameter is set to **TRUE** and File History is already configured for the current user, the current configuration is replaced with the selected one and future backups after performed to the target device containing the selected configuration.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## See also

[FhReassociation](https://learn.microsoft.com/windows/desktop/DevNotes/fhreassociation)

[IFhReassociation](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhreassociation)

[IFhReassociation::SelectConfiguration](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhreassociation-selectconfiguration)