# MFGetAttribute2UINT32asUINT64 function

## Description

Gets an attribute whose value is two **UINT32** values packed into a **UINT64**.

## Parameters

### `pAttributes` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store.

### `guidKey` [in]

A **GUID** that identifies which value to retrieve. The attribute type must be **MF_ATTRIBUTE_UINT64**.

### `punHigh32` [out]

Receives the high-order 32 bits.

### `punLow32` [out]

Receives the low-order 32 bits.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ATTRIBUTENOTFOUND** | The specified key was not found. |
| **MF_E_INVALIDTYPE** | The attribute value is not a **UINT64**. |

## Remarks

Internally, this function calls [IMFAttributes::GetUINT64](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getuint64) to get the **UINT64** value, and [Unpack2UINT32AsUINT64](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-unpack2uint32asuint64) to unpack the two 32-bit values.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)