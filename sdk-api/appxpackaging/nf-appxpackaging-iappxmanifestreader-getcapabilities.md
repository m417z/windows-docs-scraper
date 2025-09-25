# IAppxManifestReader::GetCapabilities

## Description

Gets the list of capabilities requested by the package.

## Parameters

### `capabilities` [out, retval]

Type: **[APPX_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_capabilities)***

The list of capabilities requested by the package. This is a bitwise combination of the values of the enumeration.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Capabilities are specified using the [Capability](https://learn.microsoft.com/uwp/schemas/appxpackage/appxmanifestschema/element-capability) element in the package manifest.

If no package capabilities are defined in the manifest, this method returns **S_OK** with a zero value.

## See also

[IAppxManifestReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestreader)