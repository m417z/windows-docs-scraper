# WMDM\_STORAGE\_ENUM\_MODE enumeration

The **WMDM\_STORAGE\_ENUM\_MODE** enumeration type defines how the content on the storage is to be enumerated. This enumeration is used by [**IWMDMStorage3::SetEnumPreference**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage3-setenumpreference).

## Constants

**ENUM\_MODE\_RAW**

Enumerates content on the storage just as it is organized in the file system of the storage.

**ENUM\_MODE\_USE\_DEVICE\_PREF**

Enumerates content on the storage based on the device preference as indicated by the *UseMetadataViews* device parameter.

**ENUM\_MODE\_METADATA\_VIEWS**

Enumerates content on the storage by organizing the content based on a metadata view.

**ENUM\_MODE\_USE\_DEVICE\_PREF**

Enumerates content on the storage based on the device preference as indicated by the *UseMetadataViews* device parameter.

**ENUM\_MODE\_METADATA\_VIEWS**

Enumerates content on the storage by organizing the content based on a metadata view.

**ENUM\_MODE\_METADATA\_VIEWS**

Enumerates content on the storage by organizing the content based on a metadata view.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Wmdm.idl |

## See also

[**Enumeration Types**](https://learn.microsoft.com/windows/win32/wmdm/enumeration-types)

