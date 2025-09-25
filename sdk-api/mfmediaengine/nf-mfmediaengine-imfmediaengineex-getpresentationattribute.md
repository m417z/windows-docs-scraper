# IMFMediaEngineEx::GetPresentationAttribute

## Description

Gets a presentation attribute from the media resource.

## Parameters

### `guidMFAttribute` [in]

The attribute to query.

For a list of presentation attributes, see [Presentation Descriptor Attributes](https://learn.microsoft.com/windows/desktop/medfound/presentation-descriptor-attributes).

### `pvValue` [out]

A pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) that receives the value. The method fills the **PROPVARIANT** with a copy of the stored value. The caller must free the **PROPVARIANT** by calling [PropVariantClear](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantclear).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineex)