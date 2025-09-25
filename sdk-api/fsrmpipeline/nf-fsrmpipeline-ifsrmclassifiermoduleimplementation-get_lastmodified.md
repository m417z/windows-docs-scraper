# IFsrmClassifierModuleImplementation::get_LastModified

## Description

The last time the classifier's internal rules were modified as a 64-bit FILETIME value.

This property is read-only.

## Parameters

## Remarks

The last modified time is used by FSRM to determine whether rules using this classifier need to be run. If any classifier returns a time that is more recent than the time a file was last modified, FSRM will re-evaluate any applicable rules for that file.

A value corresponding to **FsrmNeverModified** can be returned if the classifier has no internal policies that are ever updated. An example of such a classifier is one that bases its classification decision on the attributes (such as path or owner) or content of a file.

A value corresponding to **FsrmAlwaysModified** can be returned if the classifier has internal policies that affect rules that always need to be reevaluated on each classification run. In this case, applicable rules for each file will always be evaluated. An example of such a classifier is one that bases its classification decision on a volatile set of policies that are outside the control of FSRM. A classifier that returns **FsrmAlwaysModified** will affect the performance of file classification because in such cases FSRM will skip optimizations that normally can avoid unnecessary rule reevaluations.

## See also

[IFsrmClassifierModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassifiermoduleimplementation)