# SCRIPT_DIGITSUBSTITUTE structure

## Description

Contains native digit and digit substitution settings.

## Members

### `NationalDigitLanguage`

Language for native substitution.

### `TraditionalDigitLanguage`

Language for traditional substitution.

### `DigitSubstitute`

Substitution type. This member is normally set by [ScriptRecordDigitSubstitution](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptrecorddigitsubstitution). However, it can also have any of the values defined in the following table.

| Value | Meaning |
| --- | --- |
| **SCRIPT_DIGITSUBSTITUTE_CONTEXT** | Substitute digits U+0030 to U+0039 using the language of the prior letters. If there are no prior letters, substitute digits using the **TraditionalDigitLanguage** member. This member is normally set to the primary language of the locale passed to [ScriptRecordDigitSubstitution](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptrecorddigitsubstitution). |
| **SCRIPT_DIGITSUBSTITUTE_NATIONAL** | Substitute digits U+0030 to U+0039 using the **NationalDigitLanguage** member. This member is normally set to the national digits retrieved for the constant [LOCALE_SNATIVEDIGITS](https://learn.microsoft.com/windows/desktop/Intl/locale-snative-constants) by [ScriptRecordDigitSubstitution](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptrecorddigitsubstitution). |
| **SCRIPT_DIGITSUBSTITUTE_NONE** | Do not substitute digits. Display Unicode values U+0030 to U+0039 with European numerals. |
| **SCRIPT_DIGITSUBSTITUTE_TRADITIONAL** | Substitute digits U+0030 to U+0039 using the **TraditionalDigitLanguage** member. This member is normally set to the primary language of the locale passed to [ScriptRecordDigitSubstitution](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptrecorddigitsubstitution). |

### `dwReserved`

Reserved; initialize to 0.

## See also

[Digit Shapes](https://learn.microsoft.com/windows/desktop/Intl/digit-shapes)

[ScriptRecordDigitSubstitution](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptrecorddigitsubstitution)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Structures](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-structures)