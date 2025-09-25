# IParseDisplayName::ParseDisplayName

## Description

Parses the specified display name and creates a corresponding moniker.

## Parameters

### `pbc` [in]

A pointer to the bind context to be used in this binding operation. See [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx).

### `pszDisplayName` [in]

The display name to be parsed.

### `pchEaten` [out]

A pointer to a variable that receives the number of characters in the display name that correspond to the *ppmkOut* moniker.

### `ppmkOut` [out]

A pointer to an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) pointer variable that receives the interface pointer to the resulting moniker. If an error occurs, the implementation sets **ppmkOut* to **NULL**. If **ppmkOut* is non-**NULL**, the implementation must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref); it is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release).

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **MK_E_SYNTAX** | There is a syntax error in the display name. Parsing failed because *pszDisplayName* could only be partially resolved into a moniker. In this case, **pchEaten* has the number of characters that were successfully parsed into a moniker prefix. The parameter *ppmkOut* should be **NULL**. |
| **MK_E_NOOBJECT** | The display name does not identify a component in this namespace. |
| **E_INVALIDARG** | One or more parameters are not valid. |

## Remarks

In general, the maximum prefix of *pszDisplayName* that is syntactically valid and that represents an object should be consumed by this method and converted to a moniker.

Typically, this method is called by [MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname) or [MkParseDisplayNameEx](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775113(v=vs.85)). In the initial step of the parsing operation, these functions can retrieve the [IParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname) interface directly from an instance of a class identified with either the "@ProgID" or "ProgID" notation. Subsequent parsing steps can query for the interface on an intermediate object.

The main loops of [MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname) and [MkParseDisplayNameEx](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775113(v=vs.85)) find the next moniker piece by calling the equivalent method in the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface, that is, [IMoniker::ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-parsedisplayname), on the moniker that it currently holds. In this call to **IMoniker::ParseDisplayName**, the **MkParseDisplayName** or **MkParseDisplayNameEx** function passes **NULL** in the *pmkToLeft* parameter. If the moniker currently held is a generic composite, the call to **IMoniker::ParseDisplayName** is forwarded by that composite onto its last piece, passing the prefix of the composite to the left of the piece in *pmkToLeft*.

Some moniker classes will be able to handle this parsing internally to themselves because they are designed to designate only certain kinds of objects. Others will need to bind to the object that they designate to accomplish the parsing process. As is usual, these objects should not be released by [IMoniker::ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-parsedisplayname) but instead should be transferred to the bind context via [IBindCtx::RegisterObjectBound](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectbound) or [IBindCtx::GetRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-getrunningobjecttable) followed by [IRunningObjectTable::Register](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-register) for release at a later time.

## See also

[IMoniker::ParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-parsedisplayname)

[IParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname)

[MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname)

[MkParseDisplayNameEx](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775113(v=vs.85))