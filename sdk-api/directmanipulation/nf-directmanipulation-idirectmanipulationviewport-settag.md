# IDirectManipulationViewport::SetTag

## Description

Sets a viewport tag.

## Parameters

### `object` [in, optional]

The object portion of the tag.

### `id` [in]

The ID portion of the tag.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A tag is a pairing of an integer ID with a Component Object Model (COM) object. It can be used by an app to identify the viewport.

The object parameter is optional, so that the method can set just an ID.

#### Examples

The following example shows the syntax for this method.

```
IUnknown* pUnk = ...;
UINT32 id = ...;

HRESULT hr = pRegion->SetTag(pUnk, id);

```

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)