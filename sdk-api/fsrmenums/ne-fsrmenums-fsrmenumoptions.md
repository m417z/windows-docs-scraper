# FsrmEnumOptions enumeration

## Description

Defines the options for enumerating collections of objects.

## Constants

### `FsrmEnumOptions_None:0`

Use no options and enumerate objects synchronously.

### `FsrmEnumOptions_Asynchronous:0x1`

Reserved. Do not use.

### `FsrmEnumOptions_CheckRecycleBin:0x2`

Include items and paths that are in the system recycle bin when enumerating.

### `FsrmEnumOptions_IncludeClusterNodes:0x4`

Include objects on all nodes in a [Windows cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/windows-clustering)
when enumerating report jobs
([IFsrmReportManager::EnumReportJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-enumreportjobs)).

### `FsrmEnumOptions_IncludeDeprecatedObjects:0x8`

Include deprecated objects when enumerating.

**Windows Server 2008 R2 and Windows Server 2008:** This enumeration value is not supported before Windows Server 2012.

## Remarks

The **FsrmEnumOptions_Asynchronous** option is not supported.

## See also

[IFsrmClassificationManager::EnumModuleDefinitions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enummoduledefinitions)

[IFsrmClassificationManager::EnumPropertyDefinitions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enumpropertydefinitions)

[IFsrmClassificationManager::EnumRules](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enumrules)

[IFsrmFileGroupManager::EnumFileGroups](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilegroupmanager-enumfilegroups)

[IFsrmFileManagementJobManager::EnumFileManagementJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjobmanager-enumfilemanagementjobs)

[IFsrmFileScreenManager::EnumFileScreenExceptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreenmanager-enumfilescreenexceptions)

[IFsrmFileScreenManager::EnumFileScreens](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreenmanager-enumfilescreens)

[IFsrmFileScreenTemplateManager::EnumTemplates](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreentemplatemanager-enumtemplates)

[IFsrmQuotaManager::EnumAutoApplyQuotas](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotamanager-enumautoapplyquotas)

[IFsrmQuotaManager::EnumEffectiveQuotas](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotamanager-enumeffectivequotas)

[IFsrmQuotaManager::EnumQuotas](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotamanager-enumquotas)

[IFsrmQuotaManagerEx::IsAffectedByQuota](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotamanagerex-isaffectedbyquota)

[IFsrmQuotaTemplateManager::EnumTemplates](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotatemplatemanager-enumtemplates)

[IFsrmReportManager::EnumReportJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-enumreportjobs)