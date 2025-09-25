# IFsrmPropertyBag2::GetFieldValue

## Description

Gets the value of the specified field from the property bag.

## Parameters

### `field` [in]

Type: **[FsrmPropertyBagField](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmpropertybagfield)**

Indicates whether the volume name returned is the name of the volume being accessed, which may be a snapshot, or the volume where the property bag lives.

### `value` [out, retval]

Type: **VARIANT***

Returns the specified value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FsrmPropertyBagField](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmpropertybagfield)

[IFsrmPropertyBag2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpropertybag2)