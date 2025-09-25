# RtlIsPartialPlaceholder function

## Description

The **RtlIsPartialPlaceholder** routine determines if a file or a directory is a CloudFiles placeholder,
based on the **FileAttributes** and **ReparseTag** values of the file. These values can be obtained by listing the directory containing the file or by directly querying **FileAttributeTagInfo** on the file.

## Parameters

### `FileAttributes` [in]

Specifies the file attributes of a file or directory.

### `ReparseTag` [in]

The ReparseTag or EaSize of a file or directory.

## Return value

This function returns **TRUE** if the file or directory is a partial placeholder. It returns **FALSE** if either the
file or directory is not a placeholder or is a full placeholder.

## See also

[RtlIsPartialPlaceholderFileHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlispartialplaceholderfilehandle)

[RtlIsPartialPlaceholderFileInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlispartialplaceholderfileinfo)