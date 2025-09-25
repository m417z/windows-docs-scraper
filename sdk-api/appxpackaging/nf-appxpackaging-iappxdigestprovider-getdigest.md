## Description

Retrieves the digest representation of the app packaging object managed by the associated interface.

## Parameters

### `digest` [out]

Receives a pointer to an LPWSTR containing the digest representation of the app packaging object object managed by the associated interface.

## Return value

Returns **S_OK** on success.

## Remarks

A digest string is a hashed representation of the contents of the associated object that can be used to verify that the contents of the object haven't changed between operations.

The **IAppxDigestProvider** interface can be obtained by calling **QueryInterface** on the objects returned by the following factory interfaces, as well as the corresponding methods in different versions of the factory interfaces, such as [IAppxFactory::CreatePackageReader](https://learn.microsoft.com/windows/win32/api/appxpackaging/nf-appxpackaging-iappxfactory-createpackagereader):

- [IAppxEncryptionFactory5](https://learn.microsoft.com/windows/win32/api/appxpackaging/nn-appxpackaging-iappxencryptionfactory4)
- [IAppxBundleFactory2](https://learn.microsoft.com/windows/win32/api/appxpackaging/nn-appxpackaging-iappxbundlefactory2)
- [IAppxFactory3](https://learn.microsoft.com/windows/win32/api/appxpackaging/nn-appxpackaging-iappxfactory3)

## See also