# IWICEnumMetadataItem::Next

## Description

Advanced the current position in the enumeration.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of items to be retrieved.

### `rgeltSchema` [in, out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

An array of enumerated items. This parameter is optional.

### `rgeltId` [in, out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

An array of enumerated items.

### `rgeltValue` [in, out, optional]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

An array of enumerated items. This parameter is optional.

### `pceltFetched` [out, optional]

Type: **ULONG***

The number of items that were retrieved. This value is always less than or equal to the number of items requested.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.