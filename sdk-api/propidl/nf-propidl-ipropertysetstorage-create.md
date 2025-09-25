# IPropertySetStorage::Create

## Description

The **Create** method
creates and opens a new property set in the property set storage object.

## Parameters

### `rfmtid` [in]

The FMTID of the property set to be created. For information about FMTIDs that are well-known and predefined in the Platform SDK, see
[Predefined Property Set Format Identifiers](https://learn.microsoft.com/windows/desktop/Stg/predefined-property-set-format-identifiers).

### `pclsid` [in]

A pointer to the initial class identifier CLSID for this property set. May be **NULL**, in which case it is set to all zeroes. The CLSID is the CLSID of a class that displays and/or provides programmatic access to the property values. If there is no such class, it is recommended that the FMTID be used.

### `grfFlags` [in]

The values from [PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants).

### `grfMode` [in]

An access mode in which the newly created property set is to be opened, taken from certain values of [STGM_Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants), as described in the following Remarks section.

### `ppprstg` [out]

A pointer to the output variable that receives the [IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface pointer.

## Return value

This method supports the standard return value E_UNEXPECTED, as well as the following:

## Remarks

**IPropertySetStorage::Create** creates and opens a new property set subobject (supporting the
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface) contained in this property set storage object. The property set automatically contains code page and locale ID properties. These are set to the Unicode and the current user default, respectively.

The *grfFlags* parameter is a combination of values taken from [PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants). If the PROPSETFLAG_ANSI value from this enumeration is used, the code page is set to the current system default, rather than Unicode.

The *grfMode* parameter specifies the access mode in which the newly created set is to be opened. Values for this parameter are as in the *grfMode* parameter to
[IPropertySetStorage::Open](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-open), with the addition of the values listed in the following table.

| Value | Meaning |
| --- | --- |
| STGM_FAILIFTHERE | If another property set with the specified *fmtid* parameter exists, the call fails. This is the default action; that is, unless STGM_CREATE is specified, STGM_FAILIFTHERE is implied. |
| STGM_CREATE | If another property set with the specified *fmtid* parameter already exists, it is removed and replaced with this new one. |

The created property set is simple by default, but the caller may request a nonsimple property set by specifying the PROPSETFLAG_NONSIMPLE value in the *grfFlags* parameter. For more information about simple and nonsimple property sets, see
[Storage and Stream Objects for a Property Set](https://learn.microsoft.com/windows/desktop/Stg/storage-vs--stream-for-a-property-set).

This method is subject to the constraints of the underlying [IStorage::CreateStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-createstream) (for simple property sets) or [IStorage::CreateStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-createstorage) (for nonsimple property sets). For example, when using the
[IPropertySetStorage-Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/ipropertysetstorage-compound-file-implementation), specify STGM_SHARE_EXCLUSIVE in the *grfMode* parameter to **IPropertySetStorage::Create**. Conversely, if using the
[IPropertySetStorage-Stand-alone Implementation](https://learn.microsoft.com/windows/desktop/Stg/ipropertysetstorage-stand-alone-implementation), **IPropertySetStorage::Create** is subject to constraints that apply to the caller-specified
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage).

## See also

[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage)

[IPropertySetStorage::Open](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-open)

[PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants)

[Samples](https://learn.microsoft.com/windows/desktop/Stg/samples)

[StgCreatePropSetStg Sample](https://learn.microsoft.com/windows/desktop/Stg/stgcreatepropsetstg-sample)

[WriteRead Sample](https://learn.microsoft.com/windows/desktop/Stg/writeread-sample)