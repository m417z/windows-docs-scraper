# GOBJENUMPROC callback function

## Description

The **EnumObjectsProc** function is an application-defined callback function used with the [EnumObjects](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumobjects) function. It is used to process the object data. The **GOBJENUMPROC** type defines a pointer to this callback function. **EnumObjectsProc** is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

#### - lpData [in]

A pointer to the application-defined data passed by the [EnumObjects](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumobjects) function.

#### - lpLogObject [in]

A pointer to a [LOGPEN](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpen) or [LOGBRUSH](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush) structure describing the attributes of the object.

## Return value

To continue enumeration, the callback function must return a nonzero value. This value is user-defined.

To stop enumeration, the callback function must return zero.

## Remarks

An application must register this function by passing its address to the [EnumObjects](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumobjects) function.

## See also

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[EnumObjects](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumobjects)

[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc)

[GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock)

[LOGBRUSH](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush)

[LOGPEN](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpen)