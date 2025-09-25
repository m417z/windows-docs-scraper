# IAppxManifestReader::GetPackageDependencies

## Description

Gets an enumerator that iterates through dependencies defined in the manifest.

## Parameters

### `dependencies` [out, retval]

Type: **[IAppxManifestPackageDependenciesEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackagedependenciesenumerator)****

The enumerator that iterates through the dependencies.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If no package dependencies are found in the manifest, this method returns **S_OK** with an empty enumerator.

Call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method when you have finished using the *dependencies* object.

## See also

[IAppxManifestReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestreader)