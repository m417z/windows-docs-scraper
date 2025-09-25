# DWRITE_SCRIPT_PROPERTIES structure

## Description

The **DWRITE_SCRIPT_PROPERTIES** structure specifies script properties for caret navigation and justification.

## Members

### `isoScriptCode`

The standardized four character code for the given script.

**Note** These only include the general Unicode scripts, not any additional [ISO 15924](http://unicode.org/iso15924/iso15924-codes.html) scripts for bibliographic distinction.

### `isoScriptNumber`

The standardized numeric code, ranging 0-999.

### `clusterLookahead`

Number of characters to estimate look-ahead for complex scripts. Latin and all Kana are generally 1. Indic scripts are up to 15, and most others are 8.

**Note** Combining marks and variation selectors can produce clusters that are longer than these look-aheads, so this estimate is considered typical language use. Diacritics must be tested explicitly separately.

### `justificationCharacter`

Appropriate character to elongate the given script for justification. For example:

* Arabic - U+0640 Tatweel
* Ogham - U+1680 Ogham Space Mark

### `restrictCaretToClusters`

Restrict the caret to whole clusters, like Thai and Devanagari. Scripts such as Arabic by default allow navigation between clusters. Others like Thai always navigate across whole clusters.

### `usesWordDividers`

The language uses dividers between words, such as spaces between Latin or the Ethiopic wordspace. Examples include Latin, Greek, Devanagari, and Ethiopic. Chinese, Korean, and Thai are excluded.

### `isDiscreteWriting`

The characters are discrete units from each other. This includes both block scripts and clustered scripts. Examples include Latin, Greek, Cyrillic, Hebrew, Chinese, and Thai.

### `isBlockWriting`

The language is a block script, expanding between characters. Examples include Chinese, Japanese, Korean, and Bopomofo.

### `isDistributedWithinCluster`

The language is justified within glyph clusters, not just between glyph clusters, such as the character sequence of Thai Lu and Sara Am (U+E026, U+E033), which form a single cluster but still expand between them. Examples include Thai, Lao, and Khmer.

### `isConnectedWriting`

The script's clusters are connected to each other (such as the baseline-linked Devanagari), and no separation is added between characters.

**Note** Cursively linked scripts like Arabic are also connected (but not all connected scripts are cursive).

Examples include Devanagari, Arabic, Syriac, Bengala, Gurmukhi, and Ogham. Latin, Chinese, and Thaana are excluded.

### `isCursiveWriting`

The script is naturally cursive (Arabic and Syriac), meaning it uses other justification methods like kashida extension rather than inter-character spacing.

**Note** Although other scripts like Latin and Japanese might actually support handwritten cursive forms, they are not considered cursive scripts.

Examples include Arabic, Syriac, and Mongolian. Thaana, Devanagari, Latin, and Chinese are excluded.

### `reserved`

Reserved

## See also

[IDWriteTextAnalyzer1::GetScriptProperties](https://learn.microsoft.com/windows/win32/api/dwrite_1/nf-dwrite_1-idwritetextanalyzer1-getscriptproperties)