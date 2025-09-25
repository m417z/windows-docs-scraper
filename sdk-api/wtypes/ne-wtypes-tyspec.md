# TYSPEC enumeration

## Description

Specifies a mapping for a class ID.

## Constants

### `TYSPEC_CLSID:0`

A CLSID.

### `TYSPEC_FILEEXT`

A file name extension.

### `TYSPEC_MIMETYPE`

A MIME type.

### `TYSPEC_FILENAME`

A file name.

### `TYSPEC_PROGID`

A PROGID.

### `TYSPEC_PACKAGENAME`

A package name.

### `TYSPEC_OBJECTID`

An object ID.

## Remarks

The TYSPEC enumeration and uCLSSPEC union provide mappings to a class ID. Note that TYSPEC_CLSID is the only supported value.

``` syntax
    typedef union switch(DWORD tyspec)
        {
        case TYSPEC_CLSID:
            CLSID   clsid;
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
            GUID     PolicyId;
            } ByName;
        case TYSPEC_OBJECTID:
            struct {
            GUID     ObjectId;
            GUID     PolicyId;
            } ByObjectId;
    } uCLSSPEC;
```

## See also

[CoInstall](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinstall)