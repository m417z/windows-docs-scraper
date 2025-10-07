# IBITSExtensionSetupFactory::GetObject

## Description

Use the
**GetObject** method to retrieve a pointer to the
[IBITSExtensionSetup](https://learn.microsoft.com/windows/desktop/api/bitscfg/nn-bitscfg-ibitsextensionsetup) interface. This method performs the same binding that the
[ADsGetObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsgetobject) ADSI function performs.

## Parameters

### `Path` [in]

Null-terminated string containing the path to the directory service. For example, "IIS://\<machine name>/w3svc/1/*virtual directory*".

### `ppExtensionSetup` [out]

Use the
[IBITSExtensionSetup](https://learn.microsoft.com/windows/desktop/api/bitscfg/nn-bitscfg-ibitsextensionsetup) interface to enable and disable BITS upload for the given virtual directory.

## Return value

This method returns **S_OK** for success. Otherwise, the method failed.

## See also

[IBITSExtensionSetup](https://learn.microsoft.com/windows/desktop/api/bitscfg/nn-bitscfg-ibitsextensionsetup)