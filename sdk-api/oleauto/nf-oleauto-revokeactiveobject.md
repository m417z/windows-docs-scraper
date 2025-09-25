# RevokeActiveObject function

## Description

Ends an object's status as active.

## Parameters

### `dwRegister` [in]

A handle previously returned by [RegisterActiveObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-registeractiveobject).

### `pvReserved`

Reserved for future use. Must be null.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.