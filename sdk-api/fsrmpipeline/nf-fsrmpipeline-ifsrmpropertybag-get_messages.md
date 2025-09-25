# IFsrmPropertyBag::get_Messages

## Description

A list of the error messages that have been added to the bag.

This property is read-only.

## Parameters

## Remarks

The format of the message is
*module_name*,*rule_name*|*message*
(FSRM adds the *module_name*,*rule_name*| components to the
message that you specified when calling the
[IFsrmPropertyBag::AddMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpropertybag-addmessage) method).

## See also

[IFsrmPropertyBag](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpropertybag)

[IFsrmPropertyBag::AddMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpropertybag-addmessage)