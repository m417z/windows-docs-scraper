# SafeArrayAllocDescriptorEx function

## Description

Creates a safe array descriptor for an array of any valid variant type, including VT_RECORD, without allocating the array data.

## Parameters

### `vt` [in]

The variant type.

### `cDims` [in]

The number of dimensions in the array.

### `ppsaOut` [out]

The safe array descriptor.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* was not valid. |

## Remarks

Because [SafeArrayAllocDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayallocdescriptor) does not take a VARTYPE, it is not possible to use it to create the safe array descriptor for an array of records. The **SafeArrayAllocDescriptorEx** is used to allocate a safe array descriptor for an array of records of the given dimensions.