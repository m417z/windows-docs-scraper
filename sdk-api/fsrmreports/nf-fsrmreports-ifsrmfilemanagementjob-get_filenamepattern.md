# IFsrmFileManagementJob::get_FileNamePattern

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

A condition property: wildcard filter for names.

This property is read/write.

## Parameters

## Remarks

A file name pattern is a string expression that defines a set of file names. The expression may contain the
following wildcard characters: "*" and "?". The "*" wildcard
matches zero or more characters and the "?" wildcard matches exactly 1 character. For example,
the file name "example.cpp" matches the pattern "e*.cpp", but not "e?.cpp". The file name "ex.cpp" would match
both patterns. Note that when the file name pattern is used to compare against a specific file name, the pattern
match is case-insensitive.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)