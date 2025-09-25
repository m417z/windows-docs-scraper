# CItemIDFactory::GetPropertyStorageFromIDList

## Description

create an instance of the [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) based on the serialized property storage associated with the first ItemID.

## Parameters

### `pidl` [in]

A PIDL containing the serialized property storage.

### `riid` [in]

A reference to the IID of the [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) that is obtained by using __uuidof(IPropertyStore).

### `ppv` [out]

When this method returns, contains the address of a pointer to a new [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[CItemIDFactory](https://learn.microsoft.com/windows/desktop/api/shidfact/nl-shidfact-citemidfactory)

[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)