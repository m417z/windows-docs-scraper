# max macro

The **max** macro compares two values and returns the larger one. The data type can be any numeric data type, signed or unsigned. The data type of the arguments and the return value is the same.

## Parameters

*value1*

Specifies the first of two values.

*value2*

Specifies the second of two values.

## Return value

The return value is the greater of the two specified values.

## Remarks

The **max** macro is defined as follows:

```C++
#define max(a, b)  (((a) > (b)) ? (a) : (b))
```

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Minwindef.h |

