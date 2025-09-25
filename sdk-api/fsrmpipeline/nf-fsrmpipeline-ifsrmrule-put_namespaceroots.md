# IFsrmRule::put_NamespaceRoots

## Description

An array of directory paths that the rule is applied to when classification is run.

This property is read/write.

## Parameters

## Remarks

All subdirectories under the specified path are also scanned (recursively).

Note that FSRM supports only NTFS file systems—you cannot specify paths on ReFS, FAT,
FAT32, UDF, or other non-NTFS file system.

## See also

[IFsrmRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmrule)