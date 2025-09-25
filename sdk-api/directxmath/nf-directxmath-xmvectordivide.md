# XMVectorDivide function

## Description

Divides one instance of `XMVECTOR` by a second instance, returning the result in a third instance.

The `XMVectorDivide` divides each component of an instance of [XMVECTOR Data Type](https://learn.microsoft.com/windows/desktop/dxmath/xmvector-data-type) by the corresponding component in a
second instance of `XMVECTOR`, returning a new `XMVECTOR` instance containing the result.

## Parameters

### `V1` [in]

`XMVECTOR` instance whose components are the *dividends* of the division operation.

### `V2` [in]

`XMVECTOR` instance whose components are the *divisors* of the division operation.

## Return value

`XMVECTOR` instance whose components are the *quotient* of the division of each component of
**V1** by each corresponding component of **V2**.

## Remarks

The following code is generally faster than calling `XMVectorDivide` if the loss of precision is tolerable.

```

XMVECTOR R = XMVectorReciprocalEst(V2)
XMVectorMultiply(V1,R)

```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)