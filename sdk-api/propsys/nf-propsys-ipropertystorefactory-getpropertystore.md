# IPropertyStoreFactory::GetPropertyStore

## Description

Gets an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) object that corresponds to the supplied flags.

## Parameters

### `flags` [in]

Type: **[GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags)**

[GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags) values that modify the store that is returned.

### `pUnkFactory` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Optional. A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of an object that implements [ICreateObject](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-icreateobject). If *pUnkFactory* is provided, this method can create the handler instance using **ICreateObject** rather than [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance), if implemented. The reason to provide *pUnkFactory* is usually to create the handler in a different process. However, for most users, passing **NULL** in this parameter is sufficient.

### `riid` [in]

Type: **REFIID**

A reference to IID of the object to create.

### `ppv` [out]

Type: **void****

When this method returns, contains the address of an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface pointer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is recommended that you use the IID_PPV_ARGS macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error.