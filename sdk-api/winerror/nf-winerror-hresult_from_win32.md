# HRESULT_FROM_WIN32 macro

## Description

Maps a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) to an **HRESULT** value.

## Parameters

### `x`

The system error code.

## Remarks

This macro is defined as follows:

``` syntax
//
// HRESULT_FROM_WIN32(x) used to be a macro, however we now run it as an inline function
// to prevent double evaluation of 'x'. If you still need the macro, you can use __HRESULT_FROM_WIN32(x)
//
#define __HRESULT_FROM_WIN32(x) ((HRESULT)(x) <= 0 ? ((HRESULT)(x)) : ((HRESULT) (((x) & 0x0000FFFF) | (FACILITY_WIN32 << 16) | 0x80000000)))

#ifndef __midl
FORCEINLINE HRESULT HRESULT_FROM_WIN32(unsigned long x) {
   return (HRESULT)(x) <= 0 ? (HRESULT)(x) : (HRESULT) (((x) & 0x0000FFFF) | (FACILITY_WIN32 << 16) | 0x80000000);
}
#else
#define HRESULT_FROM_WIN32(x) __HRESULT_FROM_WIN32(x)
#endif

```

## See also

[Error Handling](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com)