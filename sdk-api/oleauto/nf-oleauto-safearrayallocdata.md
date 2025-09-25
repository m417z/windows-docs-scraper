# SafeArrayAllocData function

## Description

Allocates memory for a safe array, based on a descriptor created with [SafeArrayAllocDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayallocdescriptor).

## Parameters

### `psa` [in]

A safe array descriptor created by [SafeArrayAllocDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayallocdescriptor).

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* is not valid. |
| **E_UNEXPECTED** | The array could not be locked. |