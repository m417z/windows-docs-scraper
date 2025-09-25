# IAppxManifestPackageId2::GetArchitecture2

## Description

Gets the processor architecture as defined in the manifest.

## Parameters

### `architecture` [out, retval]

Type: **[APPX_PACKAGE_ARCHITECTURE2](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_package_architecture2)***

The architecture specified for the package.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Processor architecture information is specified using the **ProcessorArchitecture** attribute of the **Identity** element in the app package manifest.

If no architecture is defined in the manifest, this method returns the **APPX_PACKAGE_ARCHITECTURE_NEUTRAL** value of the [APPX_PACKAGE_ARCHITECTURE2](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_package_architecture2) enumeration.

## See also

[IAppxManifestPackageId2](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackageid2)