# XMMATRIX::XMMATRIX(FXMVECTOR,FXMVECTOR,FXMVECTOR,CXMVECTOR)

## Description

Initializes a new instance of the [XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix) structure from four instances of `XMVECTOR`.

Initializes a new instance of the **XMMATRIX** structure from four instances of **XMVECTOR Data Type**.

**Note** This constructor is only available when developing with C++.

## Parameters

### `R0`

Instance of **XMMATRIX** used to initialize the first row of a new instance of **XMMATRIX**.

### `R1`

Instance of **XMMATRIX** used to initialize the second row of a new instance of **XMMATRIX**.

### `R2`

Instance of **XMMATRIX** used to initialize the third row of a new instance of **XMMATRIX**.

### `R3`

Instance of **XMMATRIX** used to initialize the fourth row of a new instance of **XMMATRIX**.

## Remarks

The following two pseudocode examples demonstrate the operation of this constructor:

```cpp
XMMATRIX mat;
XMVECTOR rows[4];
//...Initialize instances of XMVECTOR
for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
        mat.m[i][j]=rows[i].v[j];
    }
}
```

Or

```cpp
XMMATRIX mat;
XMVECTOR rows[4];
//...Initialize instances of XMVECTOR
for (int i=0;i<4;i++){
    mat.r[i]=rows[i];
}
```

## See also

[XMMATRIX](https://learn.microsoft.com/windows/desktop/api/directxmath/ns-directxmath-xmmatrix)

[XMMATRIX Constructors](https://learn.microsoft.com/windows/desktop/dxmath/xmmatrix-ctor)