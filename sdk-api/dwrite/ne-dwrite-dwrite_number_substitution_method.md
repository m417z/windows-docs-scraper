# DWRITE_NUMBER_SUBSTITUTION_METHOD enumeration

## Description

Specifies how to apply number substitution on digits and related punctuation.

## Constants

### `DWRITE_NUMBER_SUBSTITUTION_METHOD_FROM_CULTURE`

Specifies that the substitution method should be determined based on the LOCALE_IDIGITSUBSTITUTION value of the specified text culture.

### `DWRITE_NUMBER_SUBSTITUTION_METHOD_CONTEXTUAL`

If the culture is Arabic or Persian, specifies that the number shapes depend on the context. Either traditional or nominal number shapes are used, depending on the nearest preceding strong character or (if there is none) the reading direction of the paragraph.

### `DWRITE_NUMBER_SUBSTITUTION_METHOD_NONE`

Specifies that code points 0x30-0x39 are always rendered as nominal numeral shapes (ones of the European number), that is, no substitution is performed.

### `DWRITE_NUMBER_SUBSTITUTION_METHOD_NATIONAL`

Specifies that numbers are rendered using the national number shapes as specified by the LOCALE_SNATIVEDIGITS value of the specified text culture.

### `DWRITE_NUMBER_SUBSTITUTION_METHOD_TRADITIONAL`

Specifies that numbers are rendered using the traditional shapes for the specified culture. For most cultures, this is the same as NativeNational. However, NativeNational results in Latin numbers for some Arabic cultures, whereasDWRITE_NUMBER_SUBSTITUTION_METHOD_TRADITIONAL results in arabic numbers for all Arabic cultures.