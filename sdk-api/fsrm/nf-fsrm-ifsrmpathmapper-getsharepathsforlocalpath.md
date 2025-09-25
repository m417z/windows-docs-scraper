# IFsrmPathMapper::GetSharePathsForLocalPath

## Description

Retrieves a list of network shares that point to the specified local path.

## Parameters

### `localPath` [in]

The local path. The string is limited to 260 characters.

### `sharePaths` [out]

A **SAFEARRAY** of **VARIANT**s. Each
**VARIANT** contains a network share path that points to the local path. The variant
type is **VT_BSTR**. Use the **bstrVal** member to access the share
path.

## Return value

The method returns the following return values.

## Remarks

When you get the path property for a quota, the path is the local path. You use this method to convert that
local path to the network path if you want to know the actual network share that is running out of space.

## See also

[FsrmPathMapper](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmpathmapper)

[IFsrmPathMapper](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmpathmapper)