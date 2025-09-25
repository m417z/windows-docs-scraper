# IMoniker::Enum

## Description

Retrieves a pointer to an enumerator for the components of a composite moniker.

## Parameters

### `fForward` [in]

If **TRUE**, enumerates the monikers from left to right. If **FALSE**, enumerates from right to left.

### `ppenumMoniker` [out]

A pointer to an [IEnumMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienummoniker) pointer variable that receives the interface pointer to the enumerator object for the moniker. When successful, the implementation must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the enumerator object. It is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs or if the moniker has no enumerable components, the implementation sets **ppenumMoniker* to **NULL**.

## Return value

This method can return the standard return values E_OUTOFMEMORY, E_UNEXPECTED, and S_OK.

## Remarks

This method must supply an [IEnumMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienummoniker) pointer to an enumerator that can enumerate the components of a moniker. For example, the implementation of the **IMoniker::Enum** method for a generic composite moniker creates an enumerator that can determine the individual monikers that make up the composite, while the **IMoniker::Enum** method for a file moniker creates an enumerator that returns monikers representing each of the components in the path.

### Notes to Callers

Call this method to examine the components that make up a composite moniker.

### Notes to Implementers

If the new moniker class has no discernible internal structure, your implementation of this method can simply return S_OK and set *ppenumMoniker* to **NULL**.

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | This method returns S_OK and sets *ppenumMoniker* to **NULL**. |
| Class moniker | This method returns S_OK and sets *ppenumMoniker* to **NULL**. |
| File moniker | This method returns S_OK and sets *ppenumMoniker* to **NULL**. |
| Generic composite moniker | If successful, this method returns S_OK and passes back an enumerator that enumerates the component monikers that make up the composite; otherwise, the method returns E_OUTOFMEMORY. |
| Item moniker | This method returns S_OK and sets *ppenumMoniker* to **NULL**. |
| OBJREF moniker | This method returns S_OK and sets *ppenumMoniker* to **NULL**. |
| Pointer moniker | This method returns E_NOTIMPL. |
| URL moniker | This method returns S_OK and sets *ppenumMoniker* to **NULL**. |

## See also

[IEnumMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienummoniker)

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)