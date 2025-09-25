# IDirectManipulationViewport::GetTag

## Description

Gets the tag value of a viewport.

## Parameters

### `riid` [in]

IID to the interface.

### `object` [out, optional]

The object portion of the tag.

### `id` [out, optional]

The identifier portion of the tag.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A tag is a pairing of an integer ID with a Component Object Model (COM) object. It can be used by an app to identify the viewport.

The out parameters are optional, so the method can return an ID, the viewport object, or both.

#### Examples

The following example show how to use this method.

```
IUnknown* pUnk;
UINT32 id;

HRESULT hr = pRegion->GetTag(IID_PPV_ARGS(&pUnk), &id);

```

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)