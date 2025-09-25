# WORDLIST_TYPE enumeration

## Description

Identifies one of the types of word lists used by spell checkers.

## Constants

### `WORDLIST_TYPE_IGNORE:0`

Words considered to be correctly spelled, but which are not offered as suggestions. This word list isn't saved and is specific to a spelling session. (The others types of word lists are saved in the default custom dictionary files, and are global.)

### `WORDLIST_TYPE_ADD:1`

Words considered to be correctly spelled and which can be offered as suggestions.

### `WORDLIST_TYPE_EXCLUDE:2`

Words considered to be incorrectly spelled.

### `WORDLIST_TYPE_AUTOCORRECT:3`

Word pairs of a misspelled word and the word that should replace it.

## Remarks

Providers should consider the following priority order when doing spell checking:
Ignored Words > AutoCorrected Words > Excluded Words > Added Words > Spell checking algorithm.

## See also

[ISpellCheckProvider::InitializeWordlist](https://learn.microsoft.com/windows/desktop/api/spellcheckprovider/nf-spellcheckprovider-ispellcheckprovider-initializewordlist)