# CreateAntiMoniker function

## Description

Creates and returns a new anti-moniker.

## Parameters

### `ppmk` [out]

The address of an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)* pointer variable that receives the interface pointer to the new anti-moniker. When successful, the function has called [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the anti-moniker and the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). When an error occurs, the anti-moniker pointer is **NULL**.

## Return value

This function can return the standard return values E_OUTOFMEMORY and S_OK.

## Remarks

You would call this function only if you are writing your own moniker class (implementing the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface). If you are writing a new moniker class that has no internal structure, you can use **CreateAntiMoniker** in your implementation of the [IMoniker::Inverse](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-inverse) method, and then check for an anti-moniker in your implementation of [IMoniker::ComposeWith](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-composewith).

Like the ".." directory, which acts as the inverse to any directory name just preceding it in a path, an anti-moniker acts as the inverse of a simple moniker that precedes it in a composite moniker. An anti-moniker is used as the inverse of simple monikers with no internal structure. For example, the system-provided implementations of file monikers, item monikers, and pointer monikers all use anti-monikers as their inverse; consequently, an anti-moniker composed to the right of one of these monikers composes to nothing.

A moniker client (an object that is using a moniker to bind to another object) typically does not know the class of a given moniker, so the client cannot be sure that an anti-moniker is the inverse. Therefore, to get the inverse of a moniker, you would call [IMoniker::Inverse](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-inverse) rather than **CreateAntiMoniker**.

To remove the last piece of a composite moniker, you would do the following:

1. Call [IMoniker::Enum](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-enum) on the composite, specifying **FALSE** as the first parameter. This creates an enumerator that returns the component monikers in reverse order.
2. Use the enumerator to retrieve the last piece of the composite.
3. Call [IMoniker::Inverse](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-inverse) on that moniker. The moniker returned by **Inverse** will remove the last piece of the composite.

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)