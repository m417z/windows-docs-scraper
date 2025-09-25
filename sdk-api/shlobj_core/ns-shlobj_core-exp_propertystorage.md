# EXP_PROPERTYSTORAGE structure

## Description

Stores information about the Shell link state. This structure is used for extra data sections that are tagged with EXP_PROPERTYSTORAGE_SIG.

## Members

### `cbSize`

Type: **DWORD**

The size of this structure, in bytes.

### `dwSignature`

Type: **DWORD**

Identifies the type of block and is the value EXP_PROPERTYSTORAGE_SIG.

### `abPropertyStorage`

Type: **BYTE[1]**

A serialized property store in the format defined by SERIALIZEDPROPSTORAGE.

## Remarks

 EXP_PROPERTYSTORAGE is used to store information serialized by the [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) object. It is named with the tag value EXP_PROPERTYSTORAGE_SIG and can be accessed via [IShellLinkDataList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinkdatalist), including operations for add, remove, and copy. This block can be used to inspect the Shell link state.