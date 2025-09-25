# IFsrmPropertyBag::get_VolumeName

## Description

The name of the volume on which the file exists.

This property is read-only.

## Parameters

## Remarks

This property contains the volume name of the location of the file being scanned. For example, if the path to a file is "P:\folder1\subfolderA\test.txt", the volume name is "P:\".

The caller should not expect that the volume name returned will consistently have a trailing backslash.

The volume name that is returned will always be the name of a live volume. In the case where the file being classified is on a snapshot, the name of the live volume that the snapshot corresponds to will be returned.

## See also

[IFsrmPropertyBag](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpropertybag)