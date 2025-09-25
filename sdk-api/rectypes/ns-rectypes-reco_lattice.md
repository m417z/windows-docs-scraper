# RECO_LATTICE structure

## Description

Serves as the entry point into a lattice.

## Members

### `ulColumnCount`

The number of columns in the lattice.

### `pLatticeColumns`

An array of [RECO_LATTICE_COLUMN](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_lattice_column) structures contained by the lattice.

### `ulPropertyCount`

The number of properties assigned to the lattice. For details about properties, see the [RECO_LATTICE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_lattice_properties) structure.

### `pGuidProperties`

An array of property GUIDs. The GUIDS for these properties can either be the properties defined in the Msinkaut.h header file (for example, line metrics) or custom properties defined by your recognizer.

### `ulBestResultColumnCount`

The number of columns that the best result consists of.

### `pulBestResultColumns`

An array containing the indexes of the columns in the *pLatticeColumns* array that makes up the best result.

### `pulBestResultIndexes`

An array of indexes of the elements in the *pLatticeElements* array of the corresponding column designated by *pulBestResultColumn*.

## Remarks

The *ulBestResultColumnCount*, *pulBestResultColumns*, and *pulBestResultIndexes* members are used together to hold information about the top alternates among all columns. These values should be filled in by the recognizer, even in the simplest case where there is no segmentation and there is only one column. Using the "together" [example](https://learn.microsoft.com/windows/desktop/tablet/recognizer-lattice-structure), if the recognizer determines that the best result is "to gather", *ulBestResultColumnCount* would be 3, the *pulBestResultColumns* array would contain [0,1,2] and the *pulBestResultIndexes* array would contain [1,0,2].

## See also

[GetLatticePtr Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getlatticeptr)

[RECO_LATTICE_COLUMN Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_lattice_column)

[RECO_LATTICE_PROPERTIES Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_lattice_properties)

[Recognizer Lattice Structure](https://learn.microsoft.com/windows/desktop/tablet/recognizer-lattice-structure)