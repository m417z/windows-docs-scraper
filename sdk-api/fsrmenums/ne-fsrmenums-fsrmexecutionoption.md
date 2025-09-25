# FsrmExecutionOption enumeration

## Description

Defines the options for how to apply the rule to the file.

## Constants

### `FsrmExecutionOption_Unknown:0`

The execution option is unknown. Do not use this value.

### `FsrmExecutionOption_EvaluateUnset:1`

The rule is applied as a default value to the file if the property is not set on the file (if none of the
storage modules returns the property).

### `FsrmExecutionOption_ReEvaluate_ConsiderExistingValue:2`

The rule is applied to the file considering default and existing values using aggregation rules (for
aggregation rules, see
[FsrmPropertyDefinitionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmpropertydefinitiontype)).

### `FsrmExecutionOption_ReEvaluate_IgnoreExistingValue:3`

The rule is applied to the file but default and existing values are ignored.

## See also

[IFsrmClassificationRule.ExecutionOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationrule-get_executionoption)