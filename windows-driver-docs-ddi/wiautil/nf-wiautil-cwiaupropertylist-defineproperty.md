# CWiauPropertyList::DefineProperty

## Description

The **CWiauPropertyList::DefineProperty** method adds a property definition to a property list object.

## Parameters

### `pIdx`

Pointer to a memory location that receives the index for the newly added property. Many other methods in this class use a property's index in order to identify the property.

### `PropId`

Specifies a property ID constant.

### `PropName`

Pointer to a name string for the property.

### `Access`

Specifies the type of access for the property, usually either WIA_PROP_READ (read-only) or WIA_PROP_RW (read/write).

### `SubType`

Specifies the property subtype, one of WIA_PROP_FLAG, WIA_PROP_LIST, WIA_PROP_RANGE, or WIA_PROP_NONE. The first three constants indicate, respectively, that a property is a set of flag values, a list of values, or a range of values. The fourth constant indicates that a property is none of these.

## Return value

This method returns S_OK if it is able to define a property successfully. If the property list does not have enough room for an additional property, the method returns E_FAIL.

## Remarks

Before a property can be added to a property list, the property list must be initialized. Do this by calling the [CWiauPropertyList::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-init) method.

## See also

[CWiauPropertyList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nl-wiautil-cwiaupropertylist)

[CWiauPropertyList::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-init)