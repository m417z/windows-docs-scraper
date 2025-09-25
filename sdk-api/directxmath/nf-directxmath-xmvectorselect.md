# XMVectorSelect function

## Description

Performs a per-component selection between two input vectors and returns the resulting vector.

## Parameters

### `V1` [in]

First vector to compare.

### `V2` [in]

Second vector to compare.

### `Control` [in]

Vector mask used to select a vector component from either *V1* or *V2*. If a component of
*Control* is zero, the returned vector's corresponding component will be the first vector's component.
If a component of *Control* is 0xFF, the returned vector's corresponding component will be the second
vector's component. For full details on how the vector mask works, see the "Remarks".

Typically, the vector used for *Control* will be either the output of a vector comparison function (such as
[XMVectorEqual](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorequal),
[XMVectorLess](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorless), or
[XMVectorGreater](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorgreater)) or it will be the output
of [XMVectorSelectControl](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorselectcontrol).

## Return value

Returns the result of the per-component selection.

## Remarks

If any given bit of *Control* is set, the corresponding bit from *V2* is used, otherwise, the
corresponding bit from *V1* is used. The following pseudocode demonstrates the operation of the function:

```
XMVECTOR Result;

Result.u[0] = (V1.u[0] & ~Control.u[0]) | (V2.u[0] & Control.u[0]);
Result.u[1] = (V1.u[1] & ~Control.u[1]) | (V2.u[1] & Control.u[1]);
Result.u[2] = (V1.u[2] & ~Control.u[2]) | (V2.u[2] & Control.u[2]);
Result.u[3] = (V1.u[3] & ~Control.u[3]) | (V2.u[3] & Control.u[3]);

return Result;
```

Manual construction of a control vector is not necessary. There are two simple ways of constructing an appropriate
control vector:

* Using the [XMVectorSelectControl](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorselectcontrol) function to construct a control vector.

  See [Using XMVectorSelect and
  XMVectorSelectControl](https://learn.microsoft.com/windows/win32/api/directxmath/nf-directxmath-xmvectorselectcontrol) for a demonstration of how this function can be used.
* The control vector can be constructed using the XM_SELECT_[0,1] constant (see
  [DirectXMath Library Constants](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-constants)). As an example, in pseudo-code, an instance of
  *Control* with the elements:

  ```
     Control = { XM_SELECT_0,   XM_SELECT_1,   XM_SELECT_0,   XM_SELECT_1 }
  ```

  would return a vector *Result* with the following components of *V1* and *V2*

  ```
     Result = { V1.X,  V2.Y,   V1.Z,   V2.W }
  ```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Component-Wise Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-component-wise)

[XMVectorSelectControl](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectorselectcontrol)