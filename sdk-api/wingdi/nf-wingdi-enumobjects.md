# EnumObjects function

## Description

The **EnumObjects** function enumerates the pens or brushes available for the specified device context (DC). This function calls the application-defined callback function once for each available object, supplying data describing that object. **EnumObjects** continues calling the callback function until the callback function returns zero or until all of the objects have been enumerated.

## Parameters

### `hdc` [in]

A handle to the DC.

### `nType` [in]

The object type. This parameter can be OBJ_BRUSH or OBJ_PEN.

### `lpFunc` [in]

A pointer to the application-defined callback function. For more information about the callback function, see the [EnumObjectsProc](https://learn.microsoft.com/previous-versions/dd162686(v=vs.85)) function.

### `lParam` [in]

A pointer to the application-defined data. The data is passed to the callback function along with the object information.

## Return value

If the function succeeds, the return value is the last value returned by the callback function. Its meaning is user-defined.

If the objects cannot be enumerated (for example, there are too many objects), the function returns zero without calling the callback function.

## See also

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[EnumObjectsProc](https://learn.microsoft.com/previous-versions/dd162686(v=vs.85))

[GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject)