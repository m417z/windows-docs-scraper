# IAppxBundleWriter::AddPayloadPackage

## Description

Adds a new app package to the bundle.

## Parameters

### `fileName` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the payload file. The file name path must be relative to the root of the package.

### `packageStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that provides the contents of *fileName*.
The stream must support [Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read), [Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek), and [Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat).

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table. Error OPC codes, in addition to OPC_E_DUPLICATE_PART may result. If the method fails, the bundle writer will close in a failed state and can't be used any more.

| Return code | Description |
| --- | --- |
| **E_NOT_VALID_STATE** | The writer is closed. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_NAME)** | The file name specified is not a valid file name or is a reserved name for a footprint file. |
| **OPC_E_DUPLICATE_PART** | The file name specified is already in use in the bundle. |

## Remarks

When the [AddPayloadFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxpackagewriter-addpayloadfile) method succeeds the contents of the specified *fileName* are written to the package and a corresponding entry is made in the package block map.

**AddPayloadPackage** reads the content of the app package from *packageStream* and stores the content in the bundle with the given *fileName*.

**AddPayloadPackage** can fail if:

* *packageStream* doesn't deliver a valid app package
* The app package delivered by *packageStream* is in a different package family than an app package already added to the bundle
* The app package delivered by *packageStream* is targeted to an architecture that can't reside in the same bundle as another app package already added to the bundle
* The app package delivered by *packageStream* has a block map that uses a different hash method than an app package already added to the bundle
* *fileName* isn't a valid file name, is a reserved name, or is already used by another app package added to the bundle

## See also

[IAppxBundleWriter](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlewriter)