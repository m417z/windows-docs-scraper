# RECO_LATTICE_COLUMN structure

## Description

Represents a column in the lattice.

## Members

### `key`

Unused. Should be set to 0 (zero).

### `cpProp`

 Holds the properties for the column.

### `cStrokes`

Count of strokes in the *pStrokes* array for the longest element in the column.

### `pStrokes`

 An array of stroke indices in the order in which they were fed to the recognizer. For example, imagine you have two strokes, stroke one containing the word "back" and stroke two containing the word "door". The column containing "back" will have a strokes array containing one ULONG {0}. The column for "door" will have a strokes array containing two ULONG items {1,2}.

### `cLatticeElements`

Number of members in *pLatticeElements*.

### `pLatticeElements`

Array of [RECO_LATTICE_ELEMENT](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_lattice_element) structures.

## Remarks

There is one column per recognition segment. Each column contains one or more elements. An element is usually a word or character that is a recognition alternate. Elements start with the same stroke index, but do not necessarily contain the same number of strokes (for example, see column 0 in the "together" [example](https://learn.microsoft.com/windows/desktop/tablet/recognizer-lattice-structure)). The structure also holds properties that are valid for the whole column.

## See also

[AddStroke Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-addstroke)

[RECO_LATTICE_ELEMENT Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_lattice_element)