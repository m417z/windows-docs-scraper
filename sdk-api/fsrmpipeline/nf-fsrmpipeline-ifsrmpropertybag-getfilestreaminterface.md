# IFsrmPropertyBag::GetFileStreamInterface

## Description

Retrieves a file stream interface that you can use to access the contents of the file.

## Parameters

### `accessMode` [in]

One or more access modes. For possible values, see the
[FsrmFileStreamingMode](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmfilestreamingmode) enumeration.

### `interfaceType` [in]

The type of streaming interface to use. For possible interface types, see the
[FsrmFileStreamingInterfaceType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmfilestreaminginterfacetype)
enumeration.

### `pStreamInterface` [out]

A **VARIANT** that contains the streaming interface that you can use to access the
contents of the file. The variant is of type **VT_DISPATCH**. Query the
**dispval** member of the variant to get the specified streaming interface.

## Return value

The method returns the following return values.

## Remarks

To ensure the caller can be authorized for access, it must be a module that has its
[IFsrmPipelineModuleDefinition::NeedsFileContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpipelinemoduledefinition-get_needsfilecontent)
property set to **TRUE**. If the *accessMode* parameter is set to
**FsrmFileStreamingMode_Write**, the caller must also be a storage module and have its
[IFsrmStorageModuleDefinition::UpdatesFileContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmstoragemoduledefinition-get_updatesfilecontent)
property set to **TRUE**.

## See also

[IFsrmPropertyBag](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpropertybag)