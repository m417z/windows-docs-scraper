# IAppxManifestPackageId::GetArchitecture

## Description

Gets the processor architecture as defined in the manifest.

## Parameters

### `architecture` [out, retval]

Type: **[APPX_PACKAGE_ARCHITECTURE](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_package_architecture)***

The architecture specified for the package.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Processor architecture information is specified using the **ProcessorArchitecture** attribute of the [Identity](https://learn.microsoft.com/uwp/schemas/appxpackage/appxmanifestschema/element-identity) element in the package manifest.

If no architecture is defined in the manifest, this method returns the **APPX_PACKAGE_ARCHITECTURE_NEUTRAL** value of the [APPX_PACKAGE_ARCHITECTURE](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_package_architecture) enumeration.

## See also

[IAppxManifestPackageId](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackageid)