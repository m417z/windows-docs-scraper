# MFSetAttribute2UINT32asUINT64 function

## Description

Packs two **UINT32** values into a **UINT64** attribute value.

## Parameters

### `pAttributes` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store.

### `guidKey` [in]

A **GUID** that identifies the value to set. If this key already exists, the function overwrites the old value.

### `unHigh32` [in]

The value to store in the high-order 32 bits of the **UINT64** value.

### `unLow32` [in]

The value to store in the low-order 32 bits of the **UINT64** value.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Internally, this functions calls [Pack2UINT32AsUINT64](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-pack2uint32asuint64) to create the 64-bit value, and [IMFAttributes::SetUINT64](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-setuint64) to set the attribute.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)