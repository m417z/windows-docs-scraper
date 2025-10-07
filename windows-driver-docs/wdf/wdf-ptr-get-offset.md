# WDF_PTR_GET_OFFSET macro

The **WDF_PTR_GET_OFFSET** macro subtracts an address from another address and returns the resulting offset value.

## Parameters

*_base*
Specifies the value to subtract from the starting address.

*_addr*
Specifies the starting address.

## Return value

Returns the offset between the two specified addresses.

## Remarks

The macro is defined as follows:

```ManagedCPlusPlus
#define WDF_PTR_GET_OFFSET(_base, _addr) \
        (size_t) (((PUCHAR) _addr) - ((PUCHAR) _base))
```

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356) |
| Minimum KMDF version | 1.5 |
| Minimum UMDF version | 2.0 |
| Header | Wdfcore.h (include Wdf.h) |

