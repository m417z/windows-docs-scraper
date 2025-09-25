# IFsrmRule::get_LastModified

## Description

The date for the last time the rule was modified.

This property is read-only.

## Parameters

## Remarks

The last-modified time is set each time you commit the rule.

The last-modified time is used by FSRM to determine whether the rule needs to be run. If any rule returns a time that is more recent than the time a file was last modified, FSRM will re-evaluate any applicable rules for that file.

## See also

[IFsrmRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmrule)