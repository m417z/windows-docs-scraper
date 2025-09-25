# FsrmCommitOptions enumeration

## Description

Defines the options for committing a collection of objects.

## Constants

### `FsrmCommitOptions_None:0`

Use no options and commit the collection of objects synchronously.

### `FsrmCommitOptions_Asynchronous:0x1`

Reserved. Do not use.

## Remarks

The **FsrmCommitOptions_Asynchronous** option is not supported.

## See also

[IFsrmCommittableCollection::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmcommittablecollection-commit)

[IFsrmFileScreenTemplate::CommitAndUpdateDerived](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreentemplate-commitandupdatederived)

[IFsrmQuotaTemplate::CommitAndUpdateDerived](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotatemplate-commitandupdatederived)