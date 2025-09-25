# IAppxManifestReader::GetDeviceCapabilities

## Description

Gets an enumerator that iterates through the device capabilities defined in the manifest.

## Parameters

### `deviceCapabilities` [out, retval]

Type: **[IAppxManifestDeviceCapabilitiesEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestdevicecapabilitiesenumerator)****

The enumerator that iterates through the device capabilities.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Device capabilities are specified using the [DeviceCapability](https://learn.microsoft.com/uwp/schemas/appxpackage/appxmanifestschema/element-devicecapability) element in the package manifest.

If no package device capabilities are defined in the manifest, this method returns **S_OK** with an empty enumerator.

Call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method when you have finished using the *deviceCapabilities* object.

## See also

[IAppxManifestReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestreader)