# IFhConfigMgr::SaveConfiguration

## Description

Saves to disk all the changes that were made in an [FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr) object since the last time that the [LoadConfiguration](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-loadconfiguration), [CreateDefaultConfiguration](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-createdefaultconfiguration) or **SaveConfiguration** method was called for the File History configuration files of the current user.

> [!NOTE]
> **IFhConfigMgr** is deprecated and may be altered or unavailable in future releases.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

This method can be called as many times as needed during the lifetime of an [FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr) object.

## See also

[FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr)

[IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr)

[IFhConfigMgr::CreateDefaultConfiguration](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-createdefaultconfiguration)

[IFhConfigMgr::LoadConfiguration](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-loadconfiguration)