# NtQueryObject function

## Description

[This function may be changed or removed from Windows without further notice.]

Retrieves various kinds of object information.

## Parameters

### `Handle` [in, optional]

The handle of the object for which information is being queried.

### `ObjectInformationClass` [in]

One of the following values, as enumerated in **OBJECT_INFORMATION_CLASS**, indicating the kind of object information to be retrieved.

| Term | Description |
| --- | --- |
| ObjectBasicInformation | Returns a **PUBLIC_OBJECT_BASIC_INFORMATION** structure as shown in the following Remarks section. |
| ObjectTypeInformation | Returns a **PUBLIC_OBJECT_TYPE_INFORMATION** structure as shown in the following Remarks section. |

### `ObjectInformation` [out, optional]

An optional pointer to a buffer where the requested information is to be returned. The size and structure of this information varies depending on the value of the *ObjectInformationClass* parameter.

### `ObjectInformationLength` [in]

The size of the buffer pointed to by the *ObjectInformation* parameter, in bytes.

### `ReturnLength` [out, optional]

An optional pointer to a location where the function writes the actual size of the information requested. If that size is less than or equal to the *ObjectInformationLength* parameter, the function copies the information into the *ObjectInformation* buffer; otherwise, it returns an NTSTATUS error code and returns in *ReturnLength* the size of the buffer required to receive the requested information.

## Return value

Returns an NTSTATUS or error code.

The forms and significance of NTSTATUS error codes are listed in the Ntstatus.h header file available in the WDK, and are described in the WDK documentation.

## Remarks

This function has no associated header file or import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) or [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function to dynamically link to Ntdll.dll.

If the *ObjectInformationClass* parameter is **ObjectBasicInformation**, the information is contained in the following structure.

``` syntax
typedef struct _PUBLIC_OBJECT_BASIC_INFORMATION {
    ULONG Attributes;
    ACCESS_MASK GrantedAccess;
    ULONG HandleCount;
    ULONG PointerCount;
    ULONG Reserved[10];    // reserved for internal use
 } PUBLIC_OBJECT_BASIC_INFORMATION, *PPUBLIC_OBJECT_BASIC_INFORMATION;

```

Available members for this structure include object attributes for the handle (**Attributes**), the access granted for the handle (**GrantedAccess**), the number of open handles to the object (**HandleCount**), and the number of kernel references to the object (**PointerCount**).

If the *ObjectInformationClass* parameter is **ObjectTypeInformation**, the information is contained in the following structure.

``` syntax
typedef struct __PUBLIC_OBJECT_TYPE_INFORMATION {
    UNICODE_STRING TypeName;
    ULONG Reserved [22];    // reserved for internal use
} PUBLIC_OBJECT_TYPE_INFORMATION, *PPUBLIC_OBJECT_TYPE_INFORMATION;

```

The only available member of this structure is the object-type name string (**TypeName**).