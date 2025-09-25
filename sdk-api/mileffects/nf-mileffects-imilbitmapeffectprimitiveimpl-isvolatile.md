# IMILBitmapEffectPrimitiveImpl::IsVolatile

## Description

Determines whether the current effect is considered volatile. If an effect is volatile, the effects framework will not attempt to cache the effect's output.

## Parameters

### `uiOutputIndex` [in]

Type: **ULONG**

A zero based index value indicating the output pin to query.

### `pfVolatile` [out, retval]

Type: **VARIANT_BOOL***

When this method returns, contains a value indicating whether the effect is considered volatile.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.