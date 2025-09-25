# ADSPROPINITPARAMS structure

## Description

The **ADSPROPINITPARAMS** structure is used with the [ADsPropGetInitInfo](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropgetinitinfo) function to obtain object data that a display specifier applies to.

## Members

### `dwSize`

The size, in bytes, of the **ADSPROPINITPARAMS** structure. Set this value before calling [ADsPropGetInitInfo](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropgetinitinfo).

### `dwFlags`

Reserved.

### `hr`

Contains an **HRESULT** value that specifies the result of the bind/get operation. If this value does not equal **S_OK**, then the remaining structure members are not initialized and should be ignored.

### `pDsObj`

Pointer to an [IDirectoryObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectoryobject) interface that represents the directory object that the display specifier applies to. Do not release this interface.

### `pwzCN`

Pointer to a null-terminated Unicode string that contains the common name of the directory object.

### `pWritableAttrs`

Pointer to an [ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info) structure that contains attribute data for the directory object.

## Remarks

The [ADsPropGetInitInfo](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropgetinitinfo) function allocates memory for the **pwzCN** and **pWritableAttrs** members. This memory is freed by the system after all display specifier objects are destroyed. The reference count for the interface pointer in **pDsObj** is not incremented by calling **ADsPropGetInitInfo**, so the interface must not be released by the caller.

## See also

[ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info)

[ADsPropGetInitInfo](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropgetinitinfo)

[IDirectoryObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectoryobject)