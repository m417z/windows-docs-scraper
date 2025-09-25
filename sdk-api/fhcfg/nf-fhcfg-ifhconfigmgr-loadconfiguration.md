# IFhConfigMgr::LoadConfiguration

## Description

Loads the File History configuration information for the current user into an [FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr) object.

> [!NOTE]
> **IFhConfigMgr** is deprecated and may be altered or unavailable in future releases.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code such as one of the values defined in the FhErrors.h header file.

## Remarks

This method or the [IFhConfigMgr::CreateDefaultConfiguration](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-createdefaultconfiguration) method must be called before any other [IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr) method can be called.

## See also

[FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr)

[IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr)

[IFhConfigMgr::CreateDefaultConfiguration](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-createdefaultconfiguration)

[IFhConfigMgr::SaveConfiguration](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-saveconfiguration)