# IAppxBundleManifestPackageInfo::GetFileName

## Description

Retrieves the file-name attribute of the package.

## Parameters

### `fileName` [out, retval]

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A string that contains the file name of the package.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can pass the package file name that **GetFileName** outputs to the [IAppxBundleReader::GetPayloadPackage](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxbundlereader-getpayloadpackage) method to access the package’s contents.

When you're done using the file name, free the memory allocated for *fileName* by using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## See also

[IAppxBundleManifestPackageInfo](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlemanifestpackageinfo)