# IPropertyStoreFactory::GetPropertyStoreForKeys

## Description

Gets an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) object, given a set of property keys. This provides an alternative, possibly faster, method of getting an **IPropertyStore** object compared to calling [IPropertyStoreFactory::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystorefactory-getpropertystore).

## Parameters

### `rgKeys` [in]

Type: **const [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)***

A pointer to an array of [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structures.

### `cKeys` [in]

Type: **UINT**

The number of [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structures in the array pointed to by *rgKeys*.

### `flags` [in]

Type: **[GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags)**

[GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags) values that modify the store that is returned.

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