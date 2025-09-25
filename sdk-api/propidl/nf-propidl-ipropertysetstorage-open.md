# IPropertySetStorage::Open

## Description

The **Open** method opens a property set contained in the property set storage object.

## Parameters

### `rfmtid` [in]

The format identifier (FMTID) of the property set to be opened. For more information about well-known and predefined FMTIDs in the Platform SDK, see
[Predefined Property Set Format Identifiers](https://learn.microsoft.com/windows/desktop/Stg/predefined-property-set-format-identifiers).

### `grfMode` [in]

The access mode in which the newly created property set is to be opened. These flags are taken from [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants). Flags that may be used and their meanings in the context of this method are described in the following Remarks section.

### `ppprstg` [out]

A pointer to the
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) pointer variable that receives the interface pointer to the requested property storage subobject.

## Return value

This method supports the standard return value E_UNEXPECTED, in addition to the following:

## Remarks

The mode in which the property set is to be opened is specified in the parameter *grfMode*. These flags are taken from [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants), but, for this method, legal values and their meanings are as follows (only certain combinations of these flag values are legal).

| Value | Meaning |
| --- | --- |
| STGM_DIRECT | Opens the property set without an additional level of transaction nesting. This is the default (the behavior if neither STGM_DIRECT nor STGM_TRANSACTED is specified). |
| STGM_TRANSACTED | Opens the property set with an additional level of transaction nesting (beyond the transaction, if any, on this property set storage object). Transacted mode is available only for nonsimple property sets. Changes in the property set must be committed with a call to [IPropertyStorage::Commit](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-commit) before they are visible to the transaction on this property set storage. |
| STGM_READ | Opens the property set with read access. Read permission is required on the property set storage. |
| STGM_WRITE | Opens the property set with write access. Not all implementations of [IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) support this mode. |
| STGM_READWRITE | Opens the property set with read and write access. Be aware that this flag is not the binary OR of the values STGM_READ and STGM_WRITE. |
| STGM_SHARE_DENY_NONE | Subsequent openings of the property set from this property set storage are not denied read or write access. (Not available in all implementations.) |
| STGM_SHARE_DENY_READ | Subsequent openings of the property set from this property set storage are denied read access. Not available in all implementations. |
| STGM_SHARE_DENY_WRITE | Subsequent openings of the property set from this property set storage are denied write access. This value is typically used in the transacted mode to prevent making unnecessary copies of an object opened by multiple users. That is, if STGM_TRANSACTED is specified, but this value is not specified, a snapshot is made, whether there are subsequent openings or not. Thus, you can improve performance by specifying this value. Not available in all implementations. |
| STGM_SHARE_EXCLUSIVE | Subsequent openings of the property set from this property set storage are not possible. Be aware that this value is not a simple binary OR of the STGM_SHARE_DENY_READ and STGM_SHARE_DENY_WRITE elements. |

This method is subject to the constraints of the underlying [IStorage::OpenStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-openstream) (for simple property sets) or [IStorage::OpenStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-openstorage) (for nonsimple property sets). For more information about simple and nonsimple property sets, see
[Storage and Stream Objects for a Property Set](https://learn.microsoft.com/windows/desktop/Stg/storage-vs--stream-for-a-property-set). For example, when using the
[IPropertySetStorage-Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/ipropertysetstorage-compound-file-implementation), you must specify STGM_SHARE_EXCLUSIVE in the *grfMode* parameter to **IPropertySetStorage::Open**. Conversely, if using the
[IPropertySetStorage-Stand-alone Implementation](https://learn.microsoft.com/windows/desktop/Stg/ipropertysetstorage-stand-alone-implementation), **IPropertySetStorage::Open** is subject to constraints that apply to the caller-specified
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage).

## See also

[EnumAll Sample](https://learn.microsoft.com/windows/desktop/Stg/enumall-sample)

[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage)

[IPropertySetStorage::Create](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-create)

[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)

[Samples](https://learn.microsoft.com/windows/desktop/Stg/samples)

[WriteRead Sample](https://learn.microsoft.com/windows/desktop/Stg/writeread-sample)