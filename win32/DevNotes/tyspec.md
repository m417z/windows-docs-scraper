# TYSPEC enumeration

Defines ways of mapping to a class ID.

## Constants

**TYSPEC\_CLSID**

A CLSID.

**TYSPEC\_FILEEXT**

A file name extension. This value is not currently supported.

**TYSPEC\_MIMETYPE**

A MIME type. This value is not currently supported.

**TYSPEC\_FILENAME**

A file name. This value is not currently supported.

**TYSPEC\_PROGID**

A PROGID. This value is not currently supported.

**TYSPEC\_PACKAGENAME**

A package name. This value is not currently supported.

**TYSPEC\_OBJECTID**

An object ID. This value is not currently supported.

## Remarks

The **uCLSSPEC** union is defined as follows:

``` syntax
typedef union switch(DWORD tyspec) {
    case TYSPEC_CLSID:
        CLSID clsid;
    case TYSPEC_FILEEXT:
        LPOLESTR pFileExt;
    case TYSPEC_MIMETYPE:
        LPOLESTR pMimeType;
    case TYSPEC_PROGID:
        LPOLESTR pProgId;
    case TYSPEC_FILENAME:
        LPOLESTR pFileName;
    case TYSPEC_PACKAGENAME:
        struct {
        LPOLESTR pPackageName;
        GUID PolicyId;
        } ByName;
    case TYSPEC_OBJECTID:
        struct {
        GUID ObjectId;
        GUID PolicyId;
        } ByObjectId;
} uCLSSPEC;
```

## Requirements

| Requirement | Value |
|----------------|---------------------------------------------------------------------------------------|
| IDL<br> | Wtypes.idl |

## See also

[**CoInstall**](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-coinstall)

