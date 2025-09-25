# MFSetAttributeSize function

## Description

Sets width and height as a single 64-bit attribute value.

## Parameters

### `pAttributes` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store.

### `guidKey` [in]

A **GUID** that identifies the value to set. If this key already exists, the function overwrites the old value.

### `unWidth` [in]

The width.

### `unHeight` [in]

The height.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Some attributes specify a width and a height as a packed **UINT64** value. This function packs the width and height values into a single **UINT64** value.

## See also

[Attributes in Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[MFGetAttributeSize](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfgetattributesize)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)