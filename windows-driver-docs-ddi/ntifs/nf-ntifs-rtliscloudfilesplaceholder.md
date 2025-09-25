# RtlIsCloudFilesPlaceholder function

## Description

The **RtlIsCloudFilesPlaceholder** routine determines if a file or a directory is a CloudFiles placeholder,
based on the **FileAttributes** and **ReparseTag** values of the file. These values can be obtained by listing the directory containing the file or by directly querying **FileAttributeTagInfo** on the file.

## Parameters

### `FileAttributes` [in]

Specifies the attributes of a file or directory.

### `ReparseTag` [in]

The ReparseTag or EaSize of a file or directory.

## Return value

This function returns **TRUE** if the file or directory is a CloudFiles partial or full placeholder. It returns **FALSE** if either the
file or directory is not a CloudFiles placeholder.

## See also

[RtlIsPartialPlaceholder](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlispartialplaceholder)