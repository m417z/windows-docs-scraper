# StgOpenPropStg function

## Description

The **StgOpenPropStg** function opens a specified property set in a specified storage or stream object. The property set supplies the system-provided, stand-alone implementation of the
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface.

## Parameters

### `pUnk` [in]

The interface pointer for **IUnknown** interface on the storage or stream object that contains the requested property set object.

### `fmtid` [in]

The FMTID of the property set to be opened.

### `grfFlags` [in]

The values from [PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants).

### `dwReserved` [in]

Reserved for future use; must be zero.

### `ppPropStg` [out]

A pointer to
an [IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)* pointer variable that receives the interface pointer to the requested property set.

## Return value

This function supports the standard return values E_INVALIDARG and E_UNEXPECTED, in addition to the following:

## Remarks

**StgOpenPropStg** opens the requested property set and supplies the system-provided, stand-alone implementation of the
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface. The requested property set is contained in the storage or stream object specified by *pUnk*. The value of the *grfFlags* parameter indicates whether *pUnk* specifies a storage or stream object. For example, if PROPSETFLAG_NONSIMPLE is set, then *pUnk* can be queried for an
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on a storage object.

In either case, this function calls *pUnk->AddRef* for the storage or stream object containing the property set. The caller must release the object when no longer required.

This function is similar to the [IPropertySetStorage::Open](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-open) method. However,
**StgOpenPropStg** adds the *pUnk* and *grfFlags* parameters, including the PROPSETFLAG_UNBUFFERED value for the *grfFlags* parameter. Use this function instead of the
Open method if you have an
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface that does not support the
[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interface, or if you want to use the PROPSETFLAG_UNBUFFERED value. For more information about using PROPSETFLAG_UNBUFFERED, see [PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants).

The *grfFlags* parameter is a combination of values taken from [PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants). The new enumeration value PROPSETFLAG_UNBUFFERED is supported. For more information, see
**PROPSETFLAG Constants**.

This function is exported out of the redistributable iprop.dll, which is included in Windows NT 4.0 with Service Pack 2 (SP2) and available as a redistributable in Windows 95 and later. In Windows 2000, it is exported out of Ole32.dll. It can also be exported out of iprop.dll in Windows 2000, but the call gets forwarded to ole32.dll.

## See also

[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage)

[IPropertySetStorage-Stand-alone Implementation](https://learn.microsoft.com/windows/desktop/Stg/ipropertysetstorage-stand-alone-implementation)

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IPropertyStorage-Stand-alone Implementation](https://learn.microsoft.com/windows/desktop/Stg/ipropertystorage-stand-alone-implementation)

[PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants)

[StgCreatePropSetStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatepropsetstg)

[StgCreatePropStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatepropstg)