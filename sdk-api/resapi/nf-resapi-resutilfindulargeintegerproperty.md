# ResUtilFindULargeIntegerProperty function

## Description

Gets a large integer property value from a property list. The **PRESUTIL_FIND_ULARGEINTEGER_PROPERTY** type defines a pointer to this function.

## Parameters

### `pPropertyList` [in]

A pointer to the property list.

### `cbPropertyListSize` [in]

The size of the data in *pPropertyList*, in bytes.

### `pszPropertyName` [in]

The name of the property.

### `plPropertyValue` [out]

The value of the property.

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error
code.

## See also

[Property List Parsing Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-list-parsing-functions)