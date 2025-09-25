# SafeArrayAllocDescriptor function

## Description

Allocates memory for a safe array descriptor.

## Parameters

### `cDims` [in]

The number of dimensions of the array.

### `ppsaOut` [out]

The safe array descriptor.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* was not valid. |
| **E_UNEXPECTED** | The array could not be locked. |

## Remarks

This function allows the creation of safe arrays that contain elements with data types other than those provided by [SafeArrayCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycreate). After creating an array descriptor using **SafeArrayAllocDescriptor**, set the element size in the array descriptor, a call [SafeArrayAllocData](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayallocdata) to allocate memory for the array elements.

#### Examples

The following example creates a safe array using the **SafeArrayAllocDescriptor** and [SafeArrayAllocData](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayallocdata) functions.

```cpp
SAFEARRAY *psa;
unsigned int ndim =  2;
HRESULT hresult = SafeArrayAllocDescriptor( ndim, &psa );
if( FAILED( hresult ) )
   return ERR_OutOfMemory;
(psa)->rgsabound[ 0 ].lLbound = 0;
(psa)->rgsabound[ 0 ].cElements = 5;
(psa)->rgsabound[ 1 ].lLbound = 1;
(psa)->rgsabound[ 1 ].cElements = 4;
hresult = SafeArrayAllocData( psa );
if( FAILED( hresult ) ) {
   SafeArrayDestroyDescriptor( psa )
   return ERR_OutOfMemory;
}
```

## See also

[SafeArrayAllocData](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayallocdata)

[SafeArrayDestroyData](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraydestroydata)

[SafeArrayDestroyDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraydestroydescriptor)