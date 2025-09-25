## Description

Returns a copy of a matrix element of an **XMFLOAT3X4**, specified by row and column arguments.

## Parameters

### `Row`

Type: **size_t**

The 0-based row number of the matrix element to retrieve.

### `Column`

Type: **size_t**

The 0-based column number of the matrix element to retrieve.

## Return value

Type: **float &**

An lvalue reference to the specified element.

## Examples

Because an lvalue reference to the matrix element is returned, you can use this operator to update the value of an element.

The code example below shows two different ways of setting *mat.m\[2,3\]* (or, equivalently, *mat._34*) to the value 42.0.

```cpp
DirectX::XMFLOAT4X3 mat;

float& a{ mat(2, 3) };
a = 42.0;

mat(2, 3) = 42.0;
```

## Remarks

## See also

[XMFLOAT3X4 structure](https://learn.microsoft.com/windows/win32/api/directxmath/ns-directxmath-xmfloat3x4)