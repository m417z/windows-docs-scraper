# IMILBitmapEffectPrimitiveImpl::IsDirty

## Description

Determines whether the effect needs to be updated.

## Parameters

### `uiOutputIndex` [in]

Type: **ULONG**

A zero based index value indicating the output pin to query.

### `pfDirty` [out, retval]

Type: **VARIANT_BOOL***

When this method returns, contains a value indicating whether the effect needs to be updated.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.