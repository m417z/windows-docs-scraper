# ObQueryNameString function

## Description

The **ObQueryNameString** routine supplies the name, if there is one, of a given object to which the caller has a pointer.

## Parameters

### `Object` [in]

A pointer to the object for which the name is requested. This parameter is required and cannot be **NULL**.

### `ObjectNameInfo` [out, optional]

A pointer to a caller-allocated buffer, of the following type, that receives the object name information:

```
typedef struct _OBJECT_NAME_INFORMATION {
  UNICODE_STRING Name;
} OBJECT_NAME_INFORMATION, *POBJECT_NAME_INFORMATION;
```

This parameter is optional and can be **NULL**. If *ObjectNameInfo* is **NULL**, *Length* must be zero.

### `Length` [in]

The size, in bytes, of the buffer that is pointed to by *ObjectNameInfo*. This parameter is optional and can be zero. If *Length* is zero, *ReturnLength* receives the size, in bytes, of the buffer that is needed to hold the object name information. A reasonable size for the buffer to accommodate most object names is 1024 bytes. If *Length* is zero, *ObjectNameInfo* can be **NULL**.

### `ReturnLength` [out]

A pointer to a caller-allocated variable that receives the size, in bytes, of the returned object name information. The object name (when present) includes a NULL-terminator and all path separators "\\" in the name. If **ObQueryNameString** returns **STATUS_INFO_LENGTH_MISMATCH**, it sets this parameter to the required buffer length.

## Return value

**ObQueryNameString** returns STATUS_SUCCESS or an NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_INFO_LENGTH_MISMATCH** | The buffer that is pointed to by *ObjectNameInfo* is too small to hold the requested object name information. *ReturnLength* points to the required buffer size. In this case, no object name information is returned. This is an error code. Be aware that if *Length* is set to zero, **STATUS_INFO_LENGTH_MISMATCH** is returned. |

## Remarks

If the given object is named and the object name was successfully acquired, the returned string is the name of the given object including as much of the object's full path as possible. In this case, **ObQueryNameString** sets **Name.Buffer** to the address of the NULL-terminated name of the specified object. The value of **Name.MaximumLength** is the length of the object name including the **NULL** termination. The value of **Name.Length** is length of the only the object name.

If the given object is unnamed, or if the object name was not successfully acquired, **ObQueryNameString** sets **Name.Buffer** to **NULL** and sets **Name.Length** and **Name.MaximumLength** to zero.

The storage for *ObjectNameInfo* can be allocated from paged or nonpaged pool.

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)