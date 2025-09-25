# RECO_LATTICE_ELEMENT structure

## Description

Corresponds to one word or one East Asian character, typically; however, an element may also correspond to a gesture, a shape, or some other code.

## Members

### `score`

Integer value that represents the shape probability assigned for this element.

### `type`

Describes whether the element contains wide string or wide character data.

`enum enumRECO_TYPE``{``RECO_TYPE_WSTRING = 0,``RECO_TYPE_WCHAR = 1``} RECO_TYPE;`

### `pData`

Holds the recognition result. This can be a string or a character.

Note: For recognizers of Latin script, the `pData` member contains a pointer to a **NULL**–terminated string of wide characters. For recognizers of East Asian characters, the `pData` member contains the wide character (WCHAR) value itself.

### `ulNextColumn`

Contains the index for the next column.

### `ulStrokeNumber`

Count of strokes used by this alternate.

### `epProp`

Properties structure. These are properties that are applicable to this element only.

For details about properties, see the [RECO_LATTICE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_lattice_properties) structure.

## See also

[RECO_LATTICE_PROPERTIES Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_lattice_properties)

[Recognizer Lattice Structure](https://learn.microsoft.com/windows/desktop/tablet/recognizer-lattice-structure)