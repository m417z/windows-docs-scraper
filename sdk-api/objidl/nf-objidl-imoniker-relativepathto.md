# IMoniker::RelativePathTo

## Description

Creates a relative moniker between this moniker and the specified moniker.

## Parameters

### `pmkOther` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the moniker to which a relative path should be taken.

### `ppmkRelPath` [out]

A pointer to an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) pointer variable that receives the interface pointer to the relative moniker. When successful, the implementation must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the new moniker; it is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs, the implementation sets **ppmkRelPath* to **NULL**.

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **MK_S_HIM** | No common prefix is shared by the two monikers and the moniker returned in *ppmkRelPath* is *pmkOther*. |
| **MK_E_NOTBINDABLE** | This moniker is a relative moniker, such as an item moniker. This moniker must be composed with the moniker of its container before a relative path can be determined. |

## Remarks

A relative moniker is analogous to a relative path (such as "..\backup"). For example, suppose you have one moniker that represents the path "c:\projects\secret\art\pict1.bmp" and another moniker that represents the path "c:\projects\secret\docs\chap1.txt". Calling **RelativePathTo** on the first moniker, passing the second one as the *pmkOther* parameter, would create a relative moniker representing the path "..\docs\chap1.txt".

### Notes to Callers

Moniker clients typically do not need to call **RelativePathTo**. This method is called primarily by the default handler for linked objects. Linked objects contain both an absolute and a relative moniker to identify the link source. (This enables link tracking if the user moves a directory tree containing both the container and source files.) The default handler calls this method to create a relative moniker from the container document to the link source. (That is, it calls **RelativePathTo** on the moniker identifying the container document, passing the moniker identifying the link source as the *pmkOther* parameter.)

If you do call **RelativePathTo**, call it only on absolute monikers, for example, a file moniker or a composite moniker whose leftmost component is a file moniker, where the file moniker represents an absolute path. Do not call this method on relative monikers.

### Notes to Implementers

Your implementation of **RelativePathTo** should first determine whether *pmkOther* is a moniker of a class that you recognize and for which you can provide special handling (for example, if it is of the same class as this moniker). If so, your implementation should determine the relative path. Otherwise, it should pass both monikers in a call to the [MonikerRelativePathTo](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-monikerrelativepathto) function, which correctly handles the generic case.

The first step in determining a relative path is determining the common prefix of this moniker and *pmkOther*. The next step is to break this moniker and *pmkOther* into two parts each, say (P, myTail) and (P, otherTail) respectively, where P is the common prefix. The correct relative path is then the inverse of myTail composed with otherTail:

Comp( Inv( myTail ), otherTail )

where Comp() represents the composition operation and Inv() represents the inverse operation.

For certain types of monikers, you cannot use your [IMoniker::Inverse](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-inverse) method to construct the inverse of myTail. For example, a file moniker returns an anti-moniker as an inverse, while its **RelativePathTo** method must use one or more file monikers that each represent the path ".." to construct the inverse of myTail.

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | This method returns MK_S_HIM and sets **ppmkRelPath* to the other moniker. |
| Class moniker | This method returns the result of calling [MonikerRelativePathTo](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-monikerrelativepathto) with *pmkSrc* equal to this moniker, *pmkOther*, *ppmkRelPath*, and **TRUE** as *dwReserved*. |
| File moniker | This method computes a moniker which when composed to the right of this moniker yields the other moniker. For example, if the path of this moniker is "C:\work\docs\report.doc" and if the other moniker is "C:\work\art\picture.bmp", the path of the computed moniker would be "..\..\art\picture.bmp". |
| Generic composite moniker | This method finds the common prefix of the two monikers and creates two monikers that consist of the remainder when the common prefix is removed. Then it creates the inverse for the remainder of this moniker and composes the remainder of the other moniker on the right of it. |
| Item moniker | This method returns MK_E_NOTBINDABLE and sets **ppmkRelPath* to **NULL**. |
| OBJREF moniker | This method returns E_NOTIMPL. |
| Pointer moniker | This method returns E_NOTIMPL. |
| URL moniker | This method returns E_NOTIMPL. |

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)

[MonikerRelativePathTo](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-monikerrelativepathto)