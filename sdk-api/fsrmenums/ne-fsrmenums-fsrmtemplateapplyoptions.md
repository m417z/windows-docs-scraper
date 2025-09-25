# FsrmTemplateApplyOptions enumeration

## Description

Defines the options for applying template changes to derived objects.

## Constants

### `FsrmTemplateApplyOptions_ApplyToDerivedMatching:1`

Apply template changes to derived objects only if the object's properties match the template's properties.

Note that the comparison is made against the template as it exists in the database, not your local copy that
has not been committed yet.

### `FsrmTemplateApplyOptions_ApplyToDerivedAll:2`

Apply template changes to all derived objects, whether their properties match the template's or not.

## See also

[IFsrmFileScreenTemplate::CommitAndUpdateDerived](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreentemplate-commitandupdatederived)

[IFsrmQuotaTemplate::CommitAndUpdateDerived](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotatemplate-commitandupdatederived)