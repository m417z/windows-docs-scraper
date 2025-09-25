# InitPropVariantFromCLSIDArray function

## Description

This routine initializes a PROPVARIANT from a given array of GUIDs. The routine takes care of allocating memory for the CLSID array using CoTaskMemAlloc.

## Parameters

### `members` [in]

Array of GUIDs to initialize PROPVARIANT value.

### `size` [in]

Size of array of GUIDs being sent in.

### `ppropvar` [out]

Pointer to a PROPVARIANT.

## Return value

This function returns S_OK if the PROPVARIANT was properly initialized, E_OUTOFMEMORY if there was not enough memory to allocate the CLSID array in *ppropvar*.

## Remarks

## See also