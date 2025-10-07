# IOptionDescription::get_Id

## Description

Gets the identifier of the spell checker option.

This property is read-only.

## Parameters

## Remarks

Option identifiers all exist in the same area. Spell checker providers should use the engine identifier and the language tag (if the option is language-specific) to disambiguate potential collisions.

Specifically, the structure for naming the option identifiers should be:

* **For the Microsoft spell checker engine:** \<language tag>:\<option name>. For example, "pt-BR:2009Reform."
* **For spell check provider engines:** \<engine id>:\<language tag>:\<option name> (the language tag may be omitted if the option is not language specific). For example, "samplespell:fr-FR:AccentedUppercase".

**Note** Spell check providers are allowed to support existing Microsoft option identifiers, but they must not create new option identifiers in the Microsoft namespace. That is, spell check providers must use the engine identifier as a prefix.

An option identifier is linked to the set of labels and the semantics associated with them. If any change needs to be made between versions to the option (adding a label to the set of labels), a new option with a new identifier must be used. The only valid change that does not require a new identifier is to change from a single label to two labels and vice-versa when the semantics for values 0 and 1 do not change.

## See also

[IOptionDescription](https://learn.microsoft.com/windows/desktop/api/spellcheck/nn-spellcheck-ioptiondescription)