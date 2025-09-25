# IFhConfigMgr::CreateDefaultConfiguration

## Description

Creates File History configuration files with default settings for the current user and loads them into an [FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr) object.

> [!NOTE]
> **IFhConfigMgr** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `OverwriteIfExists` [in]

If File History configuration files already exist for the current user and this parameter is set to **TRUE**, those files are overwritten and all previous settings and policies are reset to default values.

If File History configuration files already exist for the current user and this parameter is set to **FALSE**, those files are not overwritten and an unsuccessful **HRESULT** value is returned.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

This method or the [LoadConfiguration](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-loadconfiguration) method must be called before any other [IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr) method can be called.

## See also

[FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr)

[IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr)

[IFhConfigMgr::LoadConfiguration](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-loadconfiguration)

[IFhConfigMgr::SaveConfiguration](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-saveconfiguration)