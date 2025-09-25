# IFsrmPropertyDefinition::put_PossibleValues

## Description

The possible values to which the property can be set.

This property is read/write.

## Parameters

## Remarks

You must specify a possible values list if the property's type is
**FsrmPropertyDefinitionType_OrderedList** or
**FsrmPropertyDefinitionType_MultiChoiceList.**

You cannot delete a possible value from the list if a rule specifies the value (see
[IFsrmClassificationRule.Value](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationrule-get_value)). Deleting
the value does not remove the value from files that are currently classified using that value.

You can change the order of the values in the list. For ordered lists, changing the order can affect
aggregation the next time classification runs.

To specify descriptions for each possible value, set the
[IFsrmPropertyDefinition.ValueDescriptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpropertydefinition-get_valuedescriptions)
property.

## See also

[IFsrmPropertyDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpropertydefinition)