# GOPHER_ATTRIBUTE_ENUMERATOR callback function

## Description

[The *GopherAttributeEnumerator* function is available for use in the operating systems specified in the Requirements section.]

Prototype for a callback function that processes attribute information from a Gopher server. This callback function is installed by a call to the
[GopherGetAttribute](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gophergetattributea) function.

The **GOPHER_ATTRIBUTE_ENUMERATOR** type defines a pointer to this callback function. *GopherAttributeEnumerator* is a placeholder for the application-defined function name.

## Parameters

### `lpAttributeInfo`

Pointer to a [GOPHER_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/wininet/ns-wininet-gopher_attribute_type) structure. The
*lpBuffer* parameter of
[GopherGetAttribute](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gophergetattributea) is used for storing this structure. The
*lpBuffer* size must be equal to or greater than the value of MIN_GOPHER_ATTRIBUTE_LENGTH.

### `dwError`

Error value. This parameter is NO_ERROR if the attribute was parsed and written to the buffer successfully. If a problem was encountered, an error value is returned.

## Return value

Return **TRUE** to continue the enumeration, or **FALSE** to stop it immediately. This function is primarily used for returning the results of a Gopher+ ASK item.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

 [WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)