# CWiauPropertyList::SetCurrentValue(INT,FLOAT) (wiautil.h)

## Description

The **CWiauPropertyList::SetCurrentValue(INT,FLOAT)** method sets the current value of a property of type **FLOAT**, and sets its type to VT_R4.

## Parameters

### `index`

Specifies the property index. Set this parameter to the value in *_pIdx_ when the [CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty) method returns.

### `value`

Specifies the value that is written to the device property in the property list.

## See also

[CWiauPropertyList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nl-wiautil-cwiaupropertylist)

[CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty)