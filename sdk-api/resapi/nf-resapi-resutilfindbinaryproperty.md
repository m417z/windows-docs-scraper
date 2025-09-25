# ResUtilFindBinaryProperty function

## Description

Locates a specified binary property in a [property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) and can also return the value of the property. The **PRESUTIL_FIND_BINARY_PROPERTY** type defines a pointer to this function.

## Parameters

### `pPropertyList` [in]

Pointer to the property list in which to locate the value.

### `cbPropertyListSize` [in]

Size, in bytes, of the property list specified by *pPropertyList*.

### `pszPropertyName` [in]

Pointer to a null-terminated Unicode string containing the name of the property to locate.

### `pbPropertyValue` [out, optional]

Pointer to a **BYTE** pointer to a buffer (allocated by the function) containing a copy of the property value. You must call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) (on **pbPropertyValue*) to free the allocated memory. If no value is required, pass **NULL** for this parameter.

### `pcbPropertyValueSize` [out, optional]

Pointer to the size, in bytes, of the value returned. If no size is required, pass **NULL** for this parameter.

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_DATA** | The property list is incorrectly formatted. |
| **ERROR_NOT_ENOUGH_MEMORY** | The function could not allocate a buffer in which to return the property value. |
| **ERROR_FILE_NOT_FOUND** | The specified property could not be located in the property list. |

## Remarks

If **ResUtilFindBinaryProperty** is successful, **pbPropertyValue* points to a copy of the data stored in *pPropertyList*. Be sure to call [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) on **pbPropertyValue* to prevent memory leaks.

## See also

[ResUtilFindDwordProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfinddwordproperty)

[ResUtilFindExpandSzProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfindexpandszproperty)

[ResUtilFindExpandedSzProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfindexpandedszproperty)

[ResUtilFindLongProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfindlongproperty)

[ResUtilFindMultiSzProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfindmultiszproperty)

[ResUtilFindSzProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfindszproperty)