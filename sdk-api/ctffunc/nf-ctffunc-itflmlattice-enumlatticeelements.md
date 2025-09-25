# ITfLMLattice::EnumLatticeElements

## Description

Obtains an enumerator that contains all lattice elements contained in the lattice property that start at or after a specific offset from the start of the frame.

## Parameters

### `dwFrameStart` [in]

Specifies the offset, in 100-nanosecond units, relative to the start of the phrase, of the first element to obtain.

### `rguidType` [in]

Specifies the lattice type identifier. This can be one of the [Lattice Type](https://learn.microsoft.com/windows/desktop/TSF/lattice-types) values.

### `ppEnum` [out]

Pointer to an [IEnumTfLatticeElements](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-ienumtflatticeelements) interface pointer that receives the enumerator object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *rguidType* is unsupported by the lattice property. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[IEnumTfLatticeElements](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-ienumtflatticeelements)

[ITfLMLattice](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itflmlattice)

[Lattice Types](https://learn.microsoft.com/windows/desktop/TSF/lattice-types)