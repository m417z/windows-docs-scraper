# IAppxManifestPackageId::ComparePublisher

## Description

Compares the specified publisher with the publisher defined in the manifest.

## Parameters

### `other` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The publisher name to be compared.

### `isSame` [out, retval]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

**TRUE** if the specified publisher matches the package publisher; **FALSE** otherwise.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**.

## Remarks

Publisher information is specified using the **Publisher** attribute of the [Identity](https://learn.microsoft.com/uwp/schemas/appxpackage/appxmanifestschema/element-identity) element in the package manifest.

## See also

[IAppxManifestPackageId](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxmanifestpackageid)