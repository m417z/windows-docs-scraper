# IFsrmFileGroup::get_NonMembers

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilegroup) class.]

Retrieves or sets the filename patterns that determine the files that are excluded from the file
group.

This property is read/write.

## Parameters

## Remarks

A filename pattern is a string expression that defines a set of filenames. The expression may contain the
following wildcard characters: "*" and "?". The "*" wildcard
matches 0 or more characters and the "?" wildcard matches exactly 1 character. For example, the
file name "example.cpp" matches the pattern "e*.cpp",
but not "e?.cpp". The filename "ex.cpp" would match
both patterns. Note that when the filename pattern is used to compare against a specific filename, the pattern
match is case-insensitive.

You use the property to allow file patterns that would otherwise be blocked by the
[Members](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilegroup-get_members) property. For example, if
**Members** property uses
"*.mp*" to block mp3 files, you could set this property to
"*.mpp" to allow "*.mpp" files.

#### Examples

For an example, see
[Creating File Groups to Specify the Files to Restrict](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/creating-file-groups-to-specify-the-files-to-restrict).

## See also

[IFsrmFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilegroup)