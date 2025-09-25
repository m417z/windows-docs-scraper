# IShellItem::GetAttributes

## Description

Gets a requested set of attributes of the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object.

## Parameters

### `sfgaoMask` [in]

Type: **SFGAOF**

Specifies the attributes to retrieve. One or more of the [SFGAO](https://learn.microsoft.com/windows/desktop/shell/sfgao) values. Use a bitwise OR operator to determine the attributes to retrieve.

### `psfgaoAttribs` [out]

Type: **SFGAOF***

A pointer to a value that, when this method returns successfully, contains the requested attributes. One or more of the [SFGAO](https://learn.microsoft.com/windows/desktop/shell/sfgao) values. Only those attributes specified by *sfgaoMask* are returned; other attribute values are undefined.

## Return value

Type: **HRESULT**

Returns S_OK if the attributes returned exactly match those requested in *sfgaoMask*, S_FALSE if the attributes do not exactly match, or a standard COM error value otherwise.

## See also

[GetAttributes](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitemarray-getattributes)

[GetAttributesOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof)

[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)