## Description

Contains implementations of **Point**, **Size**, and **Rect** that store their data using the specified type.

## Members

## Syntax

```cpp
template<typename Type>
struct TypeTraits
{
    typedef D2D1_POINT_2F Point;
    typedef D2D1_SIZE_F   Size;
    typedef D2D1_RECT_F   Rect;
};

template<>
struct TypeTraits<UINT32>
{
    typedef D2D1_POINT_2U Point;
    typedef D2D1_SIZE_U   Size;
    typedef D2D1_RECT_U   Rect;
};
```