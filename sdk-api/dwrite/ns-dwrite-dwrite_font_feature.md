# DWRITE_FONT_FEATURE structure

## Description

Specifies properties used to identify and execute typographic features in the current font face.

## Members

### `nameTag`

Type: **[DWRITE_FONT_FEATURE_TAG](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_feature_tag)**

The feature OpenType name identifier.

### `parameter`

Type: **UINT32**

The execution parameter of the feature.

## Remarks

A non-zero value generally enables the feature execution, while the zero value disables it. A feature requiring a selector uses this value to indicate the selector index.

The OpenType standard provides access to typographic features available in the font by means of a feature tag with the associated parameters. The OpenType feature tag is a 4-byte identifier of the registered name of a feature. For example, the 'kern' feature name tag is used to identify the 'Kerning' feature in OpenType font. Similarly, the OpenType feature tag for 'Standard Ligatures' and 'Fractions' is 'liga' and 'frac' respectively. Since a single run can be associated with more than one typographic features, the Text String API accepts typographic settings for a run as a list of features and are executed in the order they are specified.

The value of the tag member represents the OpenType name tag of the feature, while the param value represents additional parameter for the execution of the feature referred by the tag member. Both **nameTag** and **parameter** are stored as little endian, the same convention followed by GDI. Most features treat the Param value as a binary value that indicates whether to turn the execution of the feature on or off, with it being off by default in the majority of cases. Some features, however, treat this value as an integral value representing the integer index to the list of alternate results it may produce during the execution; for instance, the feature 'Stylistic Alternates' or 'salt' uses the **parameter** value as an index to the list of alternate substituting glyphs it could produce for a specified glyph.