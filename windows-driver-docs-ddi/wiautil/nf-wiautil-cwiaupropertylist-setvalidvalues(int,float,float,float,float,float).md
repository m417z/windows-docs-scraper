# CWiauPropertyList::SetValidValues(INT,FLOAT,FLOAT,FLOAT,FLOAT,FLOAT) (wiautil.h)

## Description

The **CWiauPropertyList::SetValidValues(INT,FLOAT,FLOAT,FLOAT,FLOAT,FLOAT)** method sets the type, as well as default, current, and valid values for a **FLOAT** property associated with a range of values. The method also sets the property type to VT_R4 and subtype to WIA_PROP_RANGE.

## Parameters

### `index`

Specifies the property index. Set this parameter to the value in *_pIdx_ when the [CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty) method returns.

### `defaultValue`

Specifies the default setting of the property on the device.

### `currentValue`

Specifies the current setting of the property on the device.

### `minValue`

Specifies the minimum value in the range of values.

### `maxValue`

Specifies the maximum value in the range of values.

### `stepValue`

Specifies the increment between two successive values in the range of values.

## See also

[CWiauPropertyList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nl-wiautil-cwiaupropertylist)

[CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty)

[CWiauPropertyList::SendToWia](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-sendtowia)

[CWiauPropertyList::SetValidValues(INT,FLOAT,FLOAT,INT,PFLOAT)](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-setvalidvalues(int_float_float_int_pfloat).md)