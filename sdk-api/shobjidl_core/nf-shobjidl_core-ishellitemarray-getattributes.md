# IShellItemArray::GetAttributes

## Description

Gets the attributes of the set of items contained in an [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray). If the array contains more than one item, the attributes retrieved by this method are not the attributes of single items, but a logical combination of all of the requested attributes of all of the items.

## Parameters

### `AttribFlags` [in]

Type: **SIATTRIBFLAGS**

If the array contains a single item, this method provides the same results as [GetAttributes](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem-getattributes). However, if the array contains multiple items, the attribute sets of all the items are combined into a single attribute set and returned in the value pointed to by *psfgaoAttribs*. This parameter takes one of the following values to define how that final attribute set is determined:

#### SIATTRIBFLAGS_AND (0x00000001)

0x00000001. If there are multiple items in the array, use a bitwise AND to combine the attributes across items. For instance, if the array contains two items where one item can be moved (SFGAO_CANMOVE) and a second item cannot, the method returns (1 & 0) or 0 for that attribute bit.

#### SIATTRIBFLAGS_OR (0x00000002)

0x00000002. If there are multiple items in the array, use a bitwise OR to combine the attributes across items. For instance, if the array contains two items where one item can be moved (SFGAO_CANMOVE) and a second item cannot, the method returns (1 | 0) or 1 for that attribute bit.

#### SIATTRIBFLAGS_APPCOMPAT (0x00000003)

0x00000003. Retrieve the attributes directly from the Shell data source. To use this value, the Shell item array must have been initialized as an [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) with its contents specified as an array of child PIDLs.

#### SIATTRIBFLAGS_MASK (0x00000003)

0x00000003. A mask for SIATTRIBFLAGS_AND, SIATTRIBFLAGS_OR, and SIATTRIBFLAGS_APPCOMPAT. Callers normally do not use this value.

#### SIATTRIBFLAGS_ALLITEMS (0x00004000)

0x00004000. **Windows 7 and later**. Examine all items in the array to compute the attributes. Note that this can result in poor performance over large arrays and therefore it should be used only when needed. Cases in which you pass this flag should be extremely rare. See Remarks for more details.

### `sfgaoMask` [in]

Type: **SFGAOF**

A mask that specifies what particular attributes are being requested. A bitwise OR of one or more of the [SFGAO](https://learn.microsoft.com/windows/desktop/shell/sfgao) values.

### `psfgaoAttribs` [out]

Type: **SFGAOF***

A bitmap that, when this method returns successfully, contains the values of the requested attributes.

## Return value

Type: **HRESULT**

Returns S_OK if the attributes returned exactly match those requested in *sfgaoMask*, S_FALSE if the attributes do not exactly match, or a standard COM error value otherwise.

## Remarks

The Shell item array caches individual attributes after they have been determined.

As this method passes through the array gathering attribute information, it normally stops looking at a particular attribute after that value is irrevocably set. For instance, if the SIATTRIBFLAGS_AND flag is set, after an attribute is found not to be set on an item (a value of 0), there is no need to continue examining that attribute value on other items because the result of the AND operation will always be 0. Therefore, the final set of attributes is commonly calculated by looking at only the first few items in the array, which is all that is needed to obtain the final value. If you have a need to examine all items in the array, set the SIATTRIBFLAGS_ALLITEMS flag. However, be aware that this can slow the method's return considerably, so do not do so without cause.