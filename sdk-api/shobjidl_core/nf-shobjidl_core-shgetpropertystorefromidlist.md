# SHGetPropertyStoreFromIDList function

## Description

Retrieves an object that supports [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) or related interfaces from a pointer to an item identifier list (PIDL).

## Parameters

### `pidl` [in]

Type: **PCIDLIST_ABSOLUTE**

A pointer to an item ID list.

### `flags` [in]

Type: **[GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags)**

One or more values from the [GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags) constants. This parameter can also be **NULL**.

### `riid` [in]

Type: **REFIID**

A reference to the desired interface ID.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in *riid*. This is typically [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) or a related interface.