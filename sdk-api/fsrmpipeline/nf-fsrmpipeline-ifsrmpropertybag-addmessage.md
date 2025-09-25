# IFsrmPropertyBag::AddMessage

## Description

Adds an error message to the bag.

## Parameters

### `message` [in]

The error message to add to the bag. The message is limited to 4096 characters (the message is truncated if longer than 4096 characters).

## Return value

The method returns the following return values.

## Remarks

You can add only one message to the bag. The message is written to the error log, if enabled.

If any of the following implementations returns an error code, FSRM automatically adds a message (which does not count against the one-message limit) that includes the error code and associated message string:

* [IFsrmClassifierModuleImplementation::DoesPropertyValueApply](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassifiermoduleimplementation-doespropertyvalueapply)
* [IFsrmClassifierModuleImplementation::GetPropertyValueToApply](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassifiermoduleimplementation-getpropertyvaluetoapply)
* [IFsrmStorageModuleImplementation::LoadProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmstoragemoduleimplementation-loadproperties)
* [IFsrmStorageModuleImplementation::SaveProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmstoragemoduleimplementation-saveproperties)

## See also

[IFsrmPropertyBag](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpropertybag)

[IFsrmPropertyBag::Messages](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpropertybag-get_messages)