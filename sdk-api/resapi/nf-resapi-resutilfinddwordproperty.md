# ResUtilFindDwordProperty function

## Description

Locates an unsigned long property value in a [property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists). The **PRESUTIL_FIND_DWORD_PROPERTY** type defines a pointer to this function.

## Parameters

### `pPropertyList` [in]

Pointer to the property list in which to locate the value.

### `cbPropertyListSize` [in]

Size in bytes of the data included in *pPropertyList*.

### `pszPropertyName` [in]

Pointer to a null-terminated Unicode string containing the name of the value to locate.

### `pdwPropertyValue` [out]

Pointer to the actual value of the data stored in the property list buffer.

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_DATA** | The data is in an incorrect format. |
| **ERROR_FILE_NOT_FOUND** | The property could not be located in the property list. |

## Remarks

If the operation is successful, *pdwPropertyValue* points directly into the property list buffer. Be careful not to disturb the formatting of the property list when using *pdwPropertyValue*.

## See also

[ResUtilFindBinaryProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfindbinaryproperty)

[ResUtilFindExpandSzProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfindexpandszproperty)

[ResUtilFindExpandedSzProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfindexpandedszproperty)

[ResUtilFindLongProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfindlongproperty)

[ResUtilFindMultiSzProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfindmultiszproperty)

[ResUtilFindSzProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfindszproperty)