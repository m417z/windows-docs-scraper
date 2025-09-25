# ITfLMLattice::QueryType

## Description

Determines if a specific lattice element type is supported by the lattice property.

## Parameters

### `rguidType` [in]

Specifies the lattice type identifier. This can be one of the [Lattice Type](https://learn.microsoft.com/windows/desktop/TSF/lattice-types) values.

### `pfSupported` [out]

Pointer to a **BOOL** that receives a value that indicates if the lattice type is supported. If the lattice type is supported, this parameter receives a nonzero value and the method returns S_OK. If the lattice type is unsupported, this parameter receives zero and the method returns E_INVALIDARG.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The specified lattice type is supported. |
| **E_INVALIDARG** | Either *pfSupported* is invalid or the specified lattice type is not supported. |

## See also

[ITfLMLattice](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itflmlattice)

[Lattice Types](https://learn.microsoft.com/windows/desktop/TSF/lattice-types)