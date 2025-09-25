# OPENTYPE_FEATURE_RECORD structure

## Description

Contains information about a single OpenType feature to apply to a run.

## Members

### `tagFeature`

[OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure containing a registered or private OpenType feature tag. For information on feature tags, see [http://www.microsoft.com/typography/otspec/featuretags.htm](https://learn.microsoft.com/typography/opentype/spec/featuretags).

### `lParameter`

Value indicating how to apply the feature tag. Possible values are defined in the following table.

| Value | Description |
| --- | --- |
| 0 | Feature is disabled and should not be applied. |
| 1 | Feature is active. If the feature offers several alternatives, select the first value. |
| Greater than 1 | Feature is active. Select the alternative value at this index. Should be used only when multiple alternatives are available for a feature. |

## See also

[OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag)

[TEXTRANGE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-textrange_properties)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Structures](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-structures)