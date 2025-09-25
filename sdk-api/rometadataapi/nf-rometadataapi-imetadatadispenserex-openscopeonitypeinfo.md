# IMetaDataDispenserEx::OpenScopeOnITypeInfo

## Description

Opens the specified scope type.

## Parameters

### `pITI` [in]

Pointer to an [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo) interface that provides the type information on which to open the scope.

### `dwOpenFlags` [in]

The open mode flags.

### `riid` [in]

The desired interface.

### `ppIUnk` [out]

Pointer to a pointer to the returned interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataDispenserEx](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatadispenserex)