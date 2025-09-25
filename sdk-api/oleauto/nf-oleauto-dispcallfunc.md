# DispCallFunc function

## Description

Low-level helper for [Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) that provides machine independence for customized **Invoke**.

## Parameters

### `pvInstance`

An instance of the interface described by this type description.

### `oVft`

For FUNC_VIRTUAL functions, specifies the offset in the VTBL.

### `cc`

The calling convention. One of the CALLCONV values, such as CC_STDCALL.

### `vtReturn`

The variant type of the function return value. Use VT_EMPTY to represent void.

### `cActuals`

The number of function parameters.

### `prgvt`

An array of variant types of the function parameters.

### `prgpvarg`

The function parameters.

### `pvargResult`

The function result.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.