# VARIANT_UserSize64 function

## Description

Calculates the wire size of the [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) object, and gets its handle and data.

## Parameters

### `unnamedParam1` [in]

The data used by RPC.

### `unnamedParam2` [in]

The current buffer offset where the object will be marshaled. The method has to account for any padding needed for the object to be properly aligned when it will be marshaled to the buffer.

### `unnamedParam3` [in]

The object.

## Return value

The value obtained from the returned **HRESULT** value is **S_OK**.