# IDelayedPropertyStoreFactory::GetDelayedPropertyStore

## Description

Gets an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface object, as specified.

## Parameters

### `flags` [in]

Type: **[GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags)**

The GPS_XXX flags that modify the store that is returned. See [GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags).

### `dwStoreId` [in]

Type: **DWORD**

The property store ID. Valid values are.

#### STOREID_INNATE

Value is 0.

#### STOREID_FILE

Value is 1.

#### STOREID_FALLBACK

Value is 2.

### `riid` [in]

Type: **REFIID**

A reference to the desired IID.

### `ppv` [out]

Type: **void****

The address of an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface pointer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.