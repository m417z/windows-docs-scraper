# TEXTRANGE_PROPERTIES structure

## Description

Contains a group of OpenType features to apply to a run.

## Members

### `potfRecords`

Pointer to an array of [OPENTYPE_FEATURE_RECORD](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-opentype_feature_record) structures containing OpenType features (records) to apply to the characters in a specific range of text in a run.

### `cotfRecords`

 Number of features in the array specified by **potfRecords**.

## See also

[OPENTYPE_FEATURE_RECORD](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-opentype_feature_record)

[ScriptPlaceOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplaceopentype)

[ScriptShapeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshapeopentype)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Structures](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-structures)