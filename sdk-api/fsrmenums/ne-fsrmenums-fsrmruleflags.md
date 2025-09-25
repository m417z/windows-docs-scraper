# FsrmRuleFlags enumeration

## Description

Defines the possible states of a rule.

## Constants

### `FsrmRuleFlags_Disabled:0x100`

Disable the rule; do not use the rule to classify files.

### `FsrmRuleFlags_ClearAutomaticallyClassifiedProperty:0x400`

Clear any automatically classified property referenced by this rule if the rule conditions are no longer met.
This can be useful if the file contents or metadata changed and the property previously assigned by automatic
classification no longer apply.

**Windows Server 2012 and Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012 R2.

### `FsrmRuleFlags_ClearManuallyClassifiedProperty:0x800`

Clear any manually classified property referenced by this rule if the rule conditions are no longer met. This
can be useful if the file contents or metadata changed and the property previously assigned by manual
classification no longer apply.

**Windows Server 2012 and Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012 R2.

### `FsrmRuleFlags_Invalid:0x1000`

Do not set this flag. FSRM sets this flag if the classifier that uses the rule is either disabled or not
registered with FSRM. If this flag is set FSRM will not use the rule to classify files.

## Remarks

You cannot set **FsrmRuleFlags_Invalid**; this flag is used by FSRM.

## See also

[IFsrmRule.RuleFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmrule-get_ruleflags)