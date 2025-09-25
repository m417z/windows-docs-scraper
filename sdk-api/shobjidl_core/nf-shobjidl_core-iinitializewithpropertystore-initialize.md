# IInitializeWithPropertyStore::Initialize

## Description

Initializes a handler with an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore).

## Parameters

### `pps` [in]

Type: **[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)***

A pointer to an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method supports initializing handlers for use with OpenSearch result sets, which are returned from web services as RSS or Atom feeds.

## See also

[IInitializeWithPropertyStore](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iinitializewithpropertystore)

[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)