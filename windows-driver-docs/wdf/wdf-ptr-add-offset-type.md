# WDF_PTR_ADD_OFFSET_TYPE macro

The **WDF_PTR_ADD_OFFSET_TYPE** macro adds an offset value to an address and returns the resulting address cast to the specified type.

## Parameters

*_ptr*
Specifies an address.

*_offset*
Specifies the offset value in bytes.

*_type*
Specifies the data type to return.

## Return value

Returns a pointer to the resulting address. You select the data type of the return value in the *_type* parameter of the macro.

## Remarks

The macro is defined as follows:

```ManagedCPlusPlus
#define WDF_PTR_ADD_OFFSET_TYPE(_ptr, _offset, _type) \
    ((_type) (((PUCHAR) (_ptr)) + (_offset)))
```

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356) |
| Minimum KMDF version | 1.5 |
| Minimum UMDF version | 2.0 |
| Header | Wdfcore.h (include Wdf.h) |

