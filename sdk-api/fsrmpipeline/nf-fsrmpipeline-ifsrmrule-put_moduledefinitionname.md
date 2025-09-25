# IFsrmRule::put_ModuleDefinitionName

## Description

The name of the module definition that you want to run this rule.

This property is read/write.

## Parameters

## Remarks

FSRM provides a built-in classifier module named, Folder Classifier. The Folder Classifier classifies files based on their location (in which folder they are located). This classifier looks at the current path of the file and matches it with the path specified in the namespace roots of the classification rule. If the path is within the scope of the rule's namespace roots, then FSRM applies the rule to the file.

To get a list of modules that have been registered with FSRM, call the [IFsrmClassificationManager::EnumModuleDefinitions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enummoduledefinitions) method. To access a module's name, use the [IFsrmPipelineModuleDefinition.Name](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpipelinemoduledefinition-get_name) property.

## See also

[IFsrmRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmrule)