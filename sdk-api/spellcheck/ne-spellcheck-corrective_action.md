# CORRECTIVE_ACTION enumeration

## Description

Identifies the type of corrective action to be taken for a spelling error.

## Constants

### `CORRECTIVE_ACTION_NONE:0`

There are no errors.

### `CORRECTIVE_ACTION_GET_SUGGESTIONS:1`

The user should be prompted with a list of suggestions as returned by [ISpellChecker::Suggest](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-suggest).

### `CORRECTIVE_ACTION_REPLACE:2`

Replace the indicated erroneous text with the text provided in the suggestion. The user does not need to be prompted.

### `CORRECTIVE_ACTION_DELETE:3`

The user should be prompted to delete the indicated erroneous text.

## See also

[ISpellChecker::Suggest](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellchecker-suggest)

[ISpellingError::CorrectiveAction](https://learn.microsoft.com/windows/desktop/api/spellcheck/nf-spellcheck-ispellingerror-get_correctiveaction)