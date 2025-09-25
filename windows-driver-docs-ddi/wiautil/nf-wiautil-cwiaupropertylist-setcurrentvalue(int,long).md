## Description

The **CWiauPropertyList::SetCurrentValue(INT,LONG)** method sets the current value of a property of type **LONG**, and sets its type to VT_I4.

## Parameters

### `index`

Specifies the property index. Set this parameter to the value in **pIdx* when the [CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty) method returns.

### `value`

Specifies the value that is written to the device property in the property list.

## Return value

HRESULT

## See also

[CWiauPropertyList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nl-wiautil-cwiaupropertylist)

[CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty)