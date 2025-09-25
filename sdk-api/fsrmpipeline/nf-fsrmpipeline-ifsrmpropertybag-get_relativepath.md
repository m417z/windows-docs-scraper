# IFsrmPropertyBag::get_RelativePath

## Description

The relative path to the file.

This property is read-only.

## Parameters

## Remarks

The relative path is the path of the file relative to the volume root. For example, if the path to the file is "P:\folder1\subfolderA\test.txt", the relative path would be "\folder1\subfolderA".

The caller should not expect that the relative path returned will consistently have leading or trailing backslashes.

## See also

[IFsrmPropertyBag](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpropertybag)