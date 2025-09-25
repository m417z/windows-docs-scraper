# IOptionDescription::get_Labels

## Description

Gets the label enumerator for the spell checker option.

This property is read-only.

## Parameters

## Remarks

When there is a single label, the valid values for this option are 0 (not chosen) and 1 (chosen). When there is more than one label, the first label is associated with the value 0, the second with 1, and so on, effectively forming an enumeration. The labels should be in the language of the spell checker or localized to the user's UI language.

## See also

[IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring)

[IOptionDescription](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ioptiondescription)