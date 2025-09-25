# IAppxBundleFactory::CreateBundleWriter

## Description

Creates a write-only bundle object to which app packages can be added.

## Parameters

### `outputStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The output stream that receives the serialized package data. The stream must support at least the [Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write) method.

### `bundleVersion` [in]

Type: **UINT64**

The version number of the bundle.

 If set to 0, **CreateBundleWriter** sets the version number of the bundle to a value derived from the current system time. We recommend passing 0 so version numbers are automatically generated and each successive call generates a higher version number.

For example, if you call **CreateBundleWriter** on 2013/12/23 3:45:00 AM UTC with *bundleVersion* set to 0, the version number of the bundle becomes 2013.1223.0345.0000.

### `bundleWriter` [out, retval]

Type: **IAppxBundleWriter****

The bundle writer created by this method.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

## Remarks

Content added to the bundle is serialized out as an Appx bundle file to *outputStream*.

## See also

[IAppxBundleFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlefactory)