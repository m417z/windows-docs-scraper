# IFsrmPipelineModuleImplementation::OnLoad

## Description

Initializes the pipeline module.

## Parameters

### `moduleDefinition` [in]

Type: **[IFsrmPipelineModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduledefinition)***

An [IFsrmPipelineModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduledefinition)
instance representing the pipeline module definition to use.

### `moduleConnector` [out]

Type: **[IFsrmPipelineModuleConnector](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduleconnector)****

An [IFsrmPipelineModuleConnector](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduleconnector) instance
representing the pipeline module connector to use.

## Return value

Type: **HRESULT**

The method returns the following return values.

Other values will result in the client application receiving a
**FSRM_E_UNEXPECTED****FSRM_E_MODULE_SESSION_INITIALIZATION**
error.

**Windows Server 2008 R2:** The client application will receive a **FSRM_E_UNEXPECTED** error.

## Remarks

Your **OnLoad** implementation
must create and bind to an instance of an object implementing the
[IFsrmPipelineModuleConnector](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduleconnector) interface and
return it in the *moduleConnector* parameter. For more information on how to create and
bind this instance, see
[Initializing and Binding a Pipeline Module](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/initializing-and-binding-a-pipeline-module).

#### Examples

See
[Developing FCI Pipeline Modules](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/developing-fci-pipeline-modules).

## See also

[IFsrmClassifierModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassifiermoduleimplementation)

[IFsrmPipelineModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduleimplementation)

[IFsrmStorageModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmstoragemoduleimplementation)