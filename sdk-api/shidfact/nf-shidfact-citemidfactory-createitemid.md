# CItemIDFactory::CreateItemID

## Description

Creates an ItemID from the supplied data.

## Parameters

### `pinner` [in, optional]

A pointer to the client structure that should be copied.

### `pps` [in, out, optional]

A pointer to an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) that will be seriallized into the ItemID.

### `ppidl` [out]

When this method returns, contains a pointer to the ItemID containing the client data and [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The size of the user supplied data must equal sizeof(T). Do not use structs with variably allocated array/string members. The struct must also follow standard [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) for persistence and portability.

## See also

[CItemIDFactory](https://learn.microsoft.com/windows/desktop/api/shidfact/nl-shidfact-citemidfactory)

[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)

[SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid)