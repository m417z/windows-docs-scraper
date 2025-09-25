# IAppxBundleWriter3::Close

## Description

Finalizes the bundle package by writing footprint files at the end of the package, and closes the writer’s output stream.

## Parameters

### `hashMethodString` [in]

The string value of the **HashMethod** attribute of the [BlockMap](https://learn.microsoft.com/uwp/schemas/blockmapschema/element-blockmap) root element.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxBundleWriter3](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlewriter3)