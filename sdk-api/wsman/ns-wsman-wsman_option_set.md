# WSMAN_OPTION_SET structure

## Description

Represents a set of options. Additionally, this structure defines a flag that specifies whether all options must be understood.

## Members

### `optionsCount`

Specifies the number of options in the **options** array.

### `options`

Specifies an array of option names and values

### `optionsMustUnderstand`

If this member is **TRUE**, the plug-in must return an error if any of the options are not understood.