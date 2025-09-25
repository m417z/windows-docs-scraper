# CWiauPropertyList::CWiauPropertyList

## Description

The **CWiauPropertyList::CWiauPropertyList** method is the constructor for the **CWiauPropertyList** class.

## Remarks

The **CWiauPropertyList** constructor initializes all data members of a property list object to either **NULL** or zero. Use the [CWiauPropertyList::Init]() method to reserve memory for properties. Use the [CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty) method once per property to add it to the property list object.

## See also

[CWiauPropertyList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nl-wiautil-cwiaupropertylist)

[CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty)

[CWiauPropertyList::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-init)

[CWiauPropertyList::~CWiauPropertyList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist--cwiaupropertylist)