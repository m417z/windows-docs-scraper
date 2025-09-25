# StgCreatePropStg function

## Description

The **StgCreatePropStg** function creates and opens a property set in a specified storage or stream object. The property set supplies the system-provided, stand-alone implementation of the
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface.

## Parameters

### `pUnk` [in]

A pointer to the **IUnknown** interface on the storage or stream object that stores the new property set.

### `fmtid` [in]

The FMTID of the property set to be created.

### `pclsid` [in]

A Pointer to the initial CLSID for this property set. May be **NULL**, in which case *pclsid* is set to all zeroes.

### `grfFlags` [in]

The values from [PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants) that determine how the property set is created and opened.

### `dwReserved` [in]

Reserved; must be zero.

### `ppPropStg` [out]

The address of an
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)* pointer variable that receives the interface pointer to the new property set.

## Return value

This function supports the standard return values E_INVALIDARG and E_UNEXPECTED, in addition to the following:

## Remarks

**StgCreatePropStg** creates and opens a new property set which supplies the system-provided, stand-alone implementation of the
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface. The new property set is contained in the storage or stream object specified by *pUnk*. The value of the *grfFlags* parameter indicates whether *pUnk* specifies a storage or stream object. For example, if PROPSETFLAG_NONSIMPLE is set, then *pUnk* can be queried for an
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on a storage object.

In either case, this function calls *pUnk->AddRef* for the storage or stream object containing the property set. It is the responsibility of the caller to release the object when it is no longer needed.

This function is similar to the [IPropertySetStorage::Create](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-create) method. However,
**StgCreatePropStg** adds the *pUnk* parameter and supports the PROPSETFLAG_UNBUFFERED value for the *grfFlags* parameter. Use this function instead of the
**Create** method if you have an
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface that does not support the
[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interface, or if you want to use the PROPSETFLAG_UNBUFFERED value. For more information about using this PROPSETFLAG_UNBUFFERED enumeration value, see [PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants).

The property set automatically contains code page and locale identifier (ID) properties. These are set to the current system default and the current user default, respectively.

The *grfFlags* parameter is a combination of values taken from [PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants). The new enumeration value PROPSETFLAG_UNBUFFERED is supported. For more information, see **PROPSETFLAG Constants**.

This function is exported out of the redistributable Iprop.dll, which is included in Windows NT 4.0 with Service Pack 2 (SP2) and later and available as a redistributable in Windows 95, Windows 98 and later. In Windows 2000 and Windows XP, it is exported out of ole32.dll. It can also be exported out of iprop.dll in Windows 2000 and Windows XP, but the call gets forwarded to ole32.dll.

## See also

[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage)

[IPropertySetStorage-Stand-alone Implementation](https://learn.microsoft.com/windows/desktop/Stg/ipropertysetstorage-stand-alone-implementation)

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IPropertyStorage-Stand-alone Implementation](https://learn.microsoft.com/windows/desktop/Stg/ipropertystorage-stand-alone-implementation)

[PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants)

[StgCreatePropSetStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatepropsetstg)

[StgOpenPropStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenpropstg)