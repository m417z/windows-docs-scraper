# DsGetRdnW function

## Description

The **DsGetRdnW** function retrieves the key and value of the first relative distinguished name and a pointer to the next relative distinguished name from a distinguished name string.

## Parameters

### `ppDN` [in, out]

Address of a Unicode string pointer that, on entry, contains the distinguished name string to be parsed. The length of this string is specified in the *pcDN* parameter. If the function succeeds, this parameter is adjusted to point to the remainder of the distinguished name exclusive of current relative distinguished name. For example, if this parameter points to the string "dc=corp,dc=fabrikam,dc=com", after the function is complete this parameter points to the string ",dc=fabrikam,dc=com".

### `pcDN` [in, out]

Pointer to a **DWORD** value that, on entry, contains the number of characters in the *ppDN* string. If the function succeeds, this parameter receives the number of characters in the remainder of the distinguished name. These values do not include the null-terminated character.

### `ppKey` [out]

Pointer to a **LPCWCH** value that, if the function succeeds, receives a pointer to the key in the relative distinguished name string. This pointer is within the *ppDN* string and is not null-terminated. The *pcKey* parameter receives the number of characters in the key. This parameter is undefined if *pcKey* receives zero.

### `pcKey` [out]

Pointer to a **DWORD** value that, if the function succeeds, receives the number of characters in the key string represented by the *ppKey* parameter. If this parameter receives zero, *ppKey* is undefined.

### `ppVal` [out]

Pointer to a **LPCWCH** value that, if the function is successful, receives a pointer to the value in the relative distinguished name string. This pointer is within the *ppDN* string and is not null-terminated. The *pcVal* parameter receives the number of characters in the value. This parameter is undefined if *pcVal* receives zero.

### `pcVal` [out]

Pointer to a **DWORD** value that, if the function succeeds, receives the number of characters in the value string represented by the *ppVal* parameter. If this parameter receives zero, *ppVal* is undefined.

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 error code otherwise. Possible error codes include the following values.

## See also

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)