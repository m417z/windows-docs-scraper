# CWiauPropertyList::Init

## Description

The **CWiauPropertyList::Init** method initializes a property list object.

## Parameters

### `NumProps`

Specifies the number of properties within the property list for which to reserve space. This number can be larger than the actual number of properties in the property list, but it cannot be smaller.

## Return value

On success, the **CWiauPropertyList::Init** method returns S_OK. If the method has already been called on a given property list, the method returns E_FAIL.

## See also

[CWiauPropertyList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nl-wiautil-cwiaupropertylist)

[CWiauPropertyList::CWiauPropertyList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-cwiaupropertylist)

[CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty)