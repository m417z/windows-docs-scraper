# LPSAFEARRAY_UserSize64 function

## Description

Calculates the wire size of the [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) object, and gets its handle and data.

## Parameters

### `unnamedParam1` [in]

The data used by RPC.

### `unnamedParam2` [in]

Sets the buffer offset so that the [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) object is properly aligned when it is marshaled to the buffer.

### `unnamedParam3` [in]

The safe array that contains the data to marshal.

## Return value

The value obtained from the returned **HRESULT** value is **S_OK**.