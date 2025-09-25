# IDirectManipulationContent::SetTag

## Description

Specifies the tag object for the content.

## Parameters

### `object` [in]

The object portion of the tag.

### `id` [in]

The ID portion of the tag.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[GetTag](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationcontent-gettag) and **SetTag** are useful for associating an external COM object with the content without an external mapping between the two. They can also be used to pass information to callbacks generated for the content.

A tag is a pairing of an integer ID (*id*) with a Component Object Model (COM) object (*object*). It can be used by an app to store and retrieve an arbitrary object associated with the content.

The *object* parameter is optional, so that the method can set just the identifier portion.

## See also

[IDirectManipulationContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcontent)