# IMoniker::GetDisplayName

## Description

Retrieves the display name for the moniker.

## Parameters

### `pbc` [in]

A pointer to the [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on the bind context to be used in this operation. The bind context caches objects bound during the binding process, contains parameters that apply to all operations using the bind context, and provides the means by which the moniker implementation should retrieve information about its environment.

### `pmkToLeft` [in]

If the moniker is part of a composite moniker, pointer to the moniker to the left of this moniker. This parameter is used primarily by moniker implementers to enable cooperation between the various components of a composite moniker. Moniker clients should pass **NULL**.

### `ppszDisplayName` [out]

The address of a pointer variable that receives a pointer to the display name string for the moniker. The implementation must use [IMalloc::Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc) to allocate the string returned in *ppszDisplayName*, and the caller is responsible for calling [IMalloc::Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free) to free it. Both the caller and the implementation of this method use the COM task allocator returned by [CoGetMalloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetmalloc). If an error occurs, the implementation must set **ppszDisplayName* should be set to **NULL**.

## Return value

This method can return the standard return values E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **MK_E_EXCEEDEDDEADLINE** | The binding operation could not be completed within the time limit specified by the bind context's [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts) structure. |
| **E_NOTIMPL** | There is no display name. |

## Remarks

**GetDisplayName** provides a string that is a displayable representation of the moniker. A display name is not a complete representation of a moniker's internal state; it is simply a form that can be read by users. As a result, it is possible (though rare) for two different monikers to have the same display name. While there is no guarantee that the display name of a moniker can be parsed back into that moniker when calling the [MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname) function with it, failure to do so is rare.

### Notes to Callers

It is possible that retrieving a moniker's display name may be an expensive operation. For efficiency, you may want to cache the results of the first successful call to **GetDisplayName**, rather than making repeated calls.

### Notes to Implementers

If you are writing a moniker class in which the display name does not change, simply cache the display name and supply the cached name when requested. If the display name can change over time, getting the current display name might mean that the moniker has to access the object's storage or bind to the object, either of which can be expensive operations. If this is the case, your implementation of **GetDisplayName** should return MK_E_EXCEEDEDDEADLINE if the name cannot be retrieved by the time specified in the bind context's [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts) structure.

A moniker that is intended to be part of a generic composite moniker should include any preceding delimiter (such as '\') as part of its display name. For example, the display name returned by an item moniker includes the delimiter specified when it was created with the [CreateItemMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createitemmoniker) function. The display name for a file moniker does not include a delimiter because file monikers are always expected to be the leftmost component of a composite.

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | For each anti-moniker contained in this moniker, this method return one instance of "\..". |
| Class moniker | The display name for class monikers is of the following form: clsid:*string-clsid-no-curly-braces* *[";" *clsid-param*=*value*]:. For example, clsid:a7b90590-36fd-11cf-857d-00aa006d2ea4:. |
| File moniker | This method returns the path that the moniker represents. |
| Generic composite moniker | This method returns the concatenation of the display names returned by each component moniker of the composite. |
| Item moniker | This method returns the concatenation of the delimiter and the item name that were specified when the item moniker was created. |
| OBJREF moniker | This method obtains the display name for the OBJREF moniker. The display name is a 64-bit encoding that encapsulates the machine location, process endpoint, and interface pointer ID (IPID) of the running object. For future compatibility, the display name is restricted to characters that can be specified as part of a URL. |
| Pointer moniker | This method returns E_NOTIMPL. |
| URL moniker | The URL moniker attempts to return its full URL string. If the moniker was created with a partial URL string (see [CreateURLMonikerEx](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775103(v=vs.85))), it will first attempt to find an URL moniker in the bind context under SZ_URLCONTEXT and will next look to the moniker to its left for contextual information. If it cannot return its full URL string, it will return its partial URL string. |

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)

[MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname)