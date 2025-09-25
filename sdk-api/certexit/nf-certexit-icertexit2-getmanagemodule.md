# ICertExit2::GetManageModule

## Description

The **GetManageModule** method retrieves the [ICertManageModule](https://learn.microsoft.com/windows/desktop/api/certmod/nn-certmod-icertmanagemodule) interface associated with the [ICertExit2](https://learn.microsoft.com/windows/desktop/api/certexit/nn-certexit-icertexit2) interface by calling **GetManageModule** and passing in the address of a pointer to an **ICertManageModule**.

## Parameters

### `ppManageModule` [out]

Pointer to the [ICertManageModule](https://learn.microsoft.com/windows/desktop/api/certmod/nn-certmod-icertmanagemodule) interface associated with the [ICertExit2](https://learn.microsoft.com/windows/desktop/api/certexit/nn-certexit-icertexit2) interface.

## Return value

### C++

The return value is an **HRESULT**. A value of S_OK indicates the method was successful.

### VB

The return value is a **Variant** containing the [ICertManageModule](https://learn.microsoft.com/windows/desktop/api/certmod/nn-certmod-icertmanagemodule) interface associated with the [ICertExit2](https://learn.microsoft.com/windows/desktop/api/certexit/nn-certexit-icertexit2) interface.