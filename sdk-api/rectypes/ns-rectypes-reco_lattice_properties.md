# RECO_LATTICE_PROPERTIES structure

## Description

Contains an array of pointers to property structures.

## Members

### `cProperties`

A count of the properties in the array of properties.

### `apProps`

An array of pointers to properties.

## Remarks

The *apProps* element contains an array of pointers to properties rather than the structures themselves so that property values can be reused with multiple elements with lower memory usage.

## See also

[RECO_LATTICE_COLUMN Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_lattice_column)

[RECO_LATTICE_ELEMENT Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_lattice_element)

[RECO_LATTICE_PROPERTY Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_lattice_property)

[Recognizer Lattice Structure](https://learn.microsoft.com/windows/desktop/tablet/recognizer-lattice-structure)