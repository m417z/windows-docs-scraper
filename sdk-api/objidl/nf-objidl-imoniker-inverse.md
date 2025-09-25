# IMoniker::Inverse

## Description

Creates a moniker that is the inverse of this moniker. When composed to the right of this moniker or one of similar structure, the moniker will compose to nothing.

## Parameters

### `ppmk` [out]

The address of an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) pointer variable that receives the interface pointer to a moniker that is the inverse of this moniker. When successful, the implementation must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the new inverse moniker. It is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs, the implementation should set **ppmk* to **NULL**.

## Return value

This method can return the standard return values E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The inverse moniker has been returned successfully. |
| **MK_E_NOINVERSE** | The moniker class does not have an inverse. |

## Remarks

The inverse of a moniker is analogous to the ".." directory in MS-DOS file systems; the ".." directory acts as the inverse to any other directory name, because appending ".." to a directory name results in an empty path. In the same way, the inverse of a moniker typically is also the inverse of all monikers in the same class. However, it is not necessarily the inverse of a moniker of a different class.

The inverse of a composite moniker is a composite consisting of the inverses of the components of the original moniker, arranged in reverse order. For example, if the inverse of A is Inv( A ) and the composite of A, B, and C is Comp( A, B, C ), then

Inv( Comp( A, B, C ) ) is equal to Comp( Inv( C ), Inv( B ), Inv( A ) ).

Not all monikers have inverses. Most monikers that are themselves inverses, such as anti-monikers, do not have inverses. Monikers that have no inverse cannot have relative monikers formed from inside the objects they identify to other objects outside.

### Notes to Callers

An object that is using a moniker to locate another object usually does not know the class of the moniker it is using. To get the inverse of a moniker, you should always call **IMoniker::Inverse** rather than the [CreateAntiMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createantimoniker) function, because you cannot be certain that the moniker you're using considers an anti-moniker to be its inverse.

The **Inverse** method is also called by the implementation of the [IMoniker::RelativePathTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-relativepathto) method, to assist in constructing a relative moniker.

### Notes to Implementers

If your monikers have no internal structure, you can call the [CreateAntiMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createantimoniker) function in to get an anti-moniker in your implementation of **IMoniker::Inverse**. In your implementation of [IMoniker::ComposeWith](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-composewith), you need to check for the inverse you supply in the implementation of **Inverse**.

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | This method returns MK_E_NOINVERSE and sets **ppmk* to **NULL**. |
| Class moniker | This method returns an anti-moniker (that is, the results of calling [CreateAntiMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createantimoniker)). |
| File moniker | This method returns an anti-moniker (that is, the results of calling [CreateAntiMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createantimoniker)). |
| Generic composite moniker | This method returns a composite moniker that consists of the inverses of each of the components of the original composite, stored in reverse order. For example, if the inverse of A is Inv( A ), the inverse of the composite of A, B, and C is Comp(Inv( C ), Inv( B ), Inv( A ) ). |
| Item moniker | This method returns an anti-moniker (that is, the results of calling [CreateAntiMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createantimoniker)). |
| OBJREF moniker | This method returns an anti-moniker (that is, the results of calling [CreateAntiMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createantimoniker)). |
| Pointer moniker | This method returns an anti-moniker (that is, the results of calling [CreateAntiMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createantimoniker)). |
| URL moniker | This method returns MK_E_NOINVERSE and sets **ppmk* to **NULL**. |

## See also

[CreateAntiMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createantimoniker)

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)