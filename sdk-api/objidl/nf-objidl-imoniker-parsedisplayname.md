# IMoniker::ParseDisplayName

## Description

Converts a display name into a moniker.

## Parameters

### `pbc` [in]

A pointer to the [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on the bind context to be used in this binding operation. The bind context caches objects bound during the binding process, contains parameters that apply to all operations using the bind context, and provides the means by which the moniker implementation should retrieve information about its environment.

### `pmkToLeft` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the moniker that has been built out of the display name up to this point.

### `pszDisplayName` [in]

The remaining display name to be parsed.

### `pchEaten` [out]

A pointer to a variable that receives the number of characters in *pszDisplayName* that were consumed in this step.

### `ppmkOut` [out]

A pointer to an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) pointer variable that receives the interface pointer to the moniker that was built from *pszDisplayName*. When successful, the implementation must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the new moniker; it is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs, the implementation sets **ppmkOut* to **NULL**.

## Return value

This method can return the standard return valuesE_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The parsing operation was completed successfully. |
| **MK_E_SYNTAX** | An error in the syntax of the input components (*pmkToLeft*, this moniker, and *pszDisplayName*). For example, a file moniker returns this error if *pmkToLeft* is non-**NULL**, and an item moniker returns it if *pmkToLeft* is **NULL**. |

This method can also return the errors associated with the [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) method.

## Remarks

### Notes to Callers

Moniker clients do not typically call **ParseDisplayName** directly. Instead, they call the [MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname) function when they want to convert a display name into a moniker (for example, in implementing the **Links** dialog box for a container application, or for implementing a macro language that supports references to objects outside the document). That function first parses the initial portion of the display name itself.

It then calls **ParseDisplayName** on the moniker it has just created, passing the remainder of the display name and getting a new moniker in return; this step is repeated until the entire display name has been parsed.

### Notes to Implementers

Your implementation may be able to perform this parsing by itself if your moniker class is designed to designate only certain kinds of objects. Otherwise, you must get an [IParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) interface pointer for the object identified by the moniker-so-far (that is, the composition of *pmkToLeft* and this moniker) and then return the results of calling [IParseDisplayName::ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iparsedisplayname-parsedisplayname).

There are different strategies for getting an [IParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) pointer, as follows:

* You can try to get the object's CLSID (by calling [IPersist::GetClassID](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersist-getclassid) on the object) and then call the [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject) function, requesting the [IParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) interface on the class factory associated with that CLSID.
* You can try to bind to the object itself to get an [IParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) pointer.
* You can try binding to the object identified by *pmkToLeft* to get an [IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer) pointer and then call [IOleItemContainer::GetObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleitemcontainer-getobject) to get an [IParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) pointer for the item.

Any objects that are bound should be registered with the bind context (see [IBindCtx::RegisterObjectBound](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectbound)) to ensure that they remain running for the duration of the parsing operation.

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | This method returns E_NOTIMPL. |
| Class moniker | This method parses the display name by binding to itself for [IParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) and asking the bound object to parse the display name into a moniker, as follows.<br><br>``` syntax hr = BindToObject(pbc, pmkToLeft, IID_IParseDisplayName, (void**)&ppdn); if (SUCCEEDED(hr)) { hr = ppdn->ParseDisplayName(pbc, lpszDisplayName, pchEaten, ppmkOut); ppdn->Release(); } return hr; ```<br><br>This method tries to acquire an [IParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) pointer, first by binding to the class factory for the object identified by the moniker and then by binding to the object itself. If either of these binding operations is successful, the file moniker passes the unparsed portion of the display name to the [IParseDisplayName::ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iparsedisplayname-parsedisplayname) method.<br><br>This method returns MK_E_SYNTAX if *pmkToLeft* is non-**NULL**. |
| File moniker | This method tries to acquire an [IParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) pointer, first by binding to the class factory for the object identified by the moniker and then by binding to the object itself. If either of these binding operations is successful, the file moniker passes the unparsed portion of the display name to the [IParseDisplayName::ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iparsedisplayname-parsedisplayname) method. |
| Generic composite moniker | This method recursively calls **IMoniker::ParseDisplayName** on the rightmost component of the composite, passing everything else as the *pmkToLeft* parameter for that call. |
| Item moniker | If *pmkToLeft* is **NULL**, this method returns MK_E_SYNTAX. Otherwise, the method calls [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) on the *pmkToLeft* parameter, requesting an [IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer) interface pointer. The method then calls [IOleItemContainer::GetObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleitemcontainer-getobject), requesting an [IParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) interface pointer to the object identified by the moniker, and passes the display name to [IParseDisplayName::ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iparsedisplayname-parsedisplayname). |
| OBJREF moniker | If *pmkToLeft* is not **NULL**, this method returns MK_E_SYNTAX. |
| Pointer moniker | This method queries the wrapped pointer for the [IParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) interface and passes the display name to [IParseDisplayName::ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iparsedisplayname-parsedisplayname). |
| URL moniker | Parses a full or partial URL string into a result moniker (ppmkOut). If *szDisplayName* represents a full URL string (for example, "http://foo.com/default.html"), the result is a new full URL moniker. If *szDisplayName* represents a partial URL string (for example, "..\default.html"), the result is a full URL that takes its context from either the bind context's SZ_URLCONTEXT object-parameter or from this URL moniker. For example, if the context moniker was "http://foo.com/pub/list.html" and *szDisplayName* was "..\default.html", the resulting URL moniker would represent "http://foo.com/default.html". |

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)

[IParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname)

[MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname)