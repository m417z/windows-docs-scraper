# IMoniker::IsSystemMoniker

## Description

Determines whether this moniker is one of the system-provided moniker classes.

## Parameters

### `pdwMksys` [out]

A pointer to a variables that receives one of the values from the [MKSYS](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-mksys) enumeration and refers to one of the COM moniker classes. This parameter cannot be **NULL**.

## Return value

This method returns S_OK to indicate that the moniker is a system moniker, and S_FALSE otherwise.

## Remarks

### Notes to Callers

New values of the [MKSYS](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-mksys) enumeration may be defined in the future; therefore, you should explicitly test for each value you are interested in.

### Notes to Implementers

Your implementation of this method must return MKSYS_NONE. You cannot use this function to identify your own monikers (for example, in your implementation of [IMoniker::ComposeWith](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-composewith)). Instead, you should use your moniker's implementation of [IPersist::GetClassID](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersist-getclassid) or use [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to test for your own private interface.

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | This method returns S_OK and passes back MKSYS_ANTIMONIKER. |
| Class moniker | This method returns S_OK and passes back MKSYS_CLASSMONIKER. |
| File moniker | This method returns S_OK and passes back MKSYS_CLASSMONIKER. |
| Generic composite moniker | This method returns S_OK and passes back MKSYS_GENERICCOMPOSITE. |
| Item moniker | This method returns S_OK and passes back MKSYS_ITEMMONIKER. |
| OBJREF moniker | This method returns S_OK and passes back MKSYS_OBJREFMONIKER. |
| Pointer moniker | This method returns S_OK and passes back MKSYS_POINTERMONIKER. |
| URL moniker | This method returns S_OK and passes back MKSYS_URLMONIKER. |

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)