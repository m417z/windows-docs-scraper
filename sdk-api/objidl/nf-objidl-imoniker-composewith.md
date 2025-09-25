# IMoniker::ComposeWith

## Description

Creates a new composite moniker by combining the current moniker with the specified moniker.

## Parameters

### `pmkRight` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the moniker to compose onto the end of this moniker.

### `fOnlyIfNotGeneric` [in]

If **TRUE**, the caller requires a nongeneric composition, so the operation should proceed only if *pmkRight* is a moniker class that this moniker can compose with in some way other than forming a generic composite. If **FALSE**, the method can create a generic composite if necessary. Most callers should set this parameter to **FALSE**.

### `ppmkComposite` [out]

A pointer to an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) pointer variable that receives the composite moniker pointer. When successful, the implementation must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the resulting moniker; it is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs or if the monikers compose to nothing (for example, composing an anti-moniker with an item moniker or a file moniker), **ppmkComposite* should be set to **NULL**.

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The monikers were successfully combined. |
| **MK_E_NEEDGENERIC** | Indicates that *fOnlyIfNotGeneric* was **TRUE**, but the monikers could not be composed together without creating a generic composite moniker. |

## Remarks

Joining two monikers together is called *composition*. Sometimes two monikers of the same class can be combined in what is called nongeneric composition. For example, a file moniker representing an incomplete path and another file moniker representing a relative path can be combined to form a single file moniker representing the complete path. Nongeneric composition for a given moniker class can be handled only in the implementation of **ComposeWith** for that moniker class.

Combining two monikers of any class is called *generic composition*, which can be accomplished through a call to the [CreateGenericComposite](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-creategenericcomposite) function.

Composition of monikers is an associative operation. That is, if A, B, and C are monikers, then, where Comp() represents the composition operation, Comp( Comp( A, B ), C )

is always equal to Comp( A, Comp( B, C ) ).

### Notes to Callers

To combine two monikers, you should call **ComposeWith** rather than calling the [CreateGenericComposite](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-creategenericcomposite) function to give the first moniker a chance to perform a nongeneric composition.

An object that provides item monikers to identify its objects would call **ComposeWith** to provide a moniker that completely identifies the location of the object. This would apply, for example, to a server that supports linking to portions of a document, or to a container that supports linking to embedded objects within its documents. In such a situation, you would do the following:

1. Create an item moniker that identifies the object.
2. Get a moniker that identifies the object's container.
3. Call **ComposeWith** on the moniker identifying the container, passing the item moniker as the *pmkRight* parameter.

### Notes to Implementers

You can use either nongeneric or generic composition to compose the current moniker with the moniker that pmkRight points to. If the class of the moniker indicated by *pmkRight* is the same as that of the current moniker, it is possible to use the contents of *pmkRight* to perform a more intelligent nongeneric composition.

In writing a new moniker class, you must decide if there are any kinds of monikers, whether of your own class or another class, to which you want to give special treatment. If so, implement **ComposeWith** to check whether *pmkRight* is a moniker of the type that should have this treatment. To do this, you can call the moniker's [IPersist::GetClassID](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersist-getclassid) method, or if you have defined a moniker object that supports a custom interface, you can call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the moniker for that interface. An example of special treatment would be the nongeneric composition of an absolute file moniker with a relative file moniker. The most common case of a special moniker is the inverse for your moniker class (whatever you return from your implementation of [IMoniker::Inverse](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-inverse)).

If *pmkRight* completely negates the receiver so that the resulting composite is empty, you should pass back **NULL** in *ppmkComposite* and return the status code S_OK.

If the *pmkRight* parameter is not of a class to which you give special treatment, examine *fOnlyIfNotGeneric* to determine what to do next. If *fOnlyIfNotGeneric* is **TRUE**, pass back **NULL** through *ppmkComposite* and return the status code MK_E_NEEDGENERIC. If *fOnlyIfNotGeneric* is **FALSE**, call the [CreateGenericComposite](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-creategenericcomposite) function to perform the composition generically.

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | If *fOnlyIfNotGeneric* is **TRUE**, this method sets *ppmkComposite* to **NULL** moniker and returns MK_E_NEEDGENERIC; otherwise, the method returns the result of combining the two monikers into a generic composite. Note that composing a file, item, or pointer moniker to the right of an anti-moniker produces a generic composite rather than composing to nothing, as would be the case if the order of composition were reversed. |
| Class moniker | Follows the contract and behaves like an item moniker in that it can return E_INVALIDARG and MK_E_NEEDGENERIC, and so forth. |
| File moniker | If *pmkRight* is an anti-moniker, the returned moniker is **NULL**. If *pmkRight* is a composite whose leftmost component is an anti-moniker, the returned moniker is the composite with the leftmost anti-moniker removed. If *pmkRight* is a file moniker, this method collapses the two monikers into a single file moniker, if possible. If not possible (for example, if both file monikers represent absolute paths, as in d:\work and e:\reports), the returned moniker is **NULL** and the return value is MK_E_SYNTAX. If *pmkRight* is neither an anti-moniker nor a file moniker, the method checks the *fOnlyIfNotGeneric* parameter; if it is **FALSE**, the method combines the two monikers into a generic composite; if it is **TRUE**, the method sets **ppmkComposite* to **NULL** and returns MK_E_NEEDGENERIC. |
| Generic composite moniker | If *fOnlyIfNotGeneric* is **TRUE**, this method sets **pmkComposite* to **NULL** and returns MK_E_NEEDGENERIC; otherwise, the method returns the result of combining the two monikers by calling the [CreateGenericComposite](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-creategenericcomposite) function. |
| Item moniker | If *pmkRight* is an anti-moniker, the returned moniker is **NULL**. If *pmkRight* is a composite whose leftmost component is an anti-moniker, the returned moniker is the composite after the leftmost anti-moniker is removed. If *pmkRight* is not an anti-moniker, the method combines the two monikers into a generic composite if *fOnlyIfNotGeneric* is **FALSE**; if *fOnlyIfNotGeneric* is **TRUE**, the method returns a **NULL** moniker and a return value of MK_E_NEEDGENERIC. |
| OBJREF moniker | If *pmkRight* is an anti-moniker, the returned moniker is **NULL**. If *pmkRight* is a composite whose leftmost component is an anti-moniker, the returned moniker is the composite with the leftmost anti-moniker removed. If *pmkRight* is neither an anti-moniker nor a composite moniker whose leftmost component is an anti-moniker, the method checks the *fOnlyIfNotGeneric* parameter. If it is **FALSE**, the method combines the two monikers into a generic composite; if it is **TRUE**, the method sets **ppmkComposite* to **NULL** and returns MK_E_NEEDGENERIC. |
| Pointer moniker | If *pmkRight* is an anti-moniker, the returned moniker is **NULL**. If *pmkRight* is a composite whose leftmost component is an anti-moniker, the returned moniker is the composite after the leftmost anti-moniker is removed. If *fOnlyIfNotGeneric* is **FALSE**, the returned moniker is a generic composite of the two monikers; otherwise, the method sets **ppmkComposite* to **NULL** and returns MK_E_NEEDGENERIC. |
| URL moniker | URL monikers support composition of two URLs: a base URL composed with a relative URL. This composition is done according to the RFC on relative URLs. If *fOnlyIfNotGeneric* is **TRUE**, the method returns MK_E_NEEDGENERIC. Otherwise, this method simply returns [CreateGenericComposite](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-creategenericcomposite)(this, pmkRight, ppmkComposite). |

## See also

[CreateGenericComposite](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-creategenericcomposite)

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)