# IDirectManipulationContent::GetTag

## Description

Retrieves the tag object set on this content.

## Parameters

### `riid` [in]

A reference to the identifier of the interface to use. The tag object typically implements this interface.

### `object` [out, optional]

The tag object.

### `id` [out, optional]

The ID portion of the tag.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**GetTag** and [SetTag](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationcontent-settag) are useful for associating an external COM object with the content without an external mapping between the two. They can also be used to pass information to callbacks generated for the content.

**GetTag** queries the tag value for the specified interface and returns a pointer to that interface.

A tag is a pairing of an integer ID (*id*) with a Component Object Model (COM) object (*object*). It can be used by an app to identify a motion.
The parameters are optional, so that the method can return both parts of the tag, the identifier portion, or the tag object.

#### Examples

The following example shows the syntax for this method.

```
IUnknown* pObject;
UINT32 id;

HRESULT hr = pContent->GetTag(IID_PPV_ARGS(&pObject), &id);

```

## See also

[IDirectManipulationContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcontent)