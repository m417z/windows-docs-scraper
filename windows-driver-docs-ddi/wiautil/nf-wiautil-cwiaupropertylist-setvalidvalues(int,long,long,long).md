## Description

The **CWiauPropertyList::SetValidValues(INT,LONG,LONG,LONG)** method sets the type, as well as default, current, and valid values for a property whose values are defined by a flag. The method also sets the property type to VT_I4 and subtype to WIA_PROP_FLAG.

## Parameters

### `index`

Specifies the property index. Set this parameter to the value in **pIdx* when the [CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty) method returns.

### `defaultValue`

Specifies the default setting of the property on the device.

### `currentValue`

Specifies the current setting of the property on the device.

### `validFlags`

Specifies a value containing all of the valid flags.

## Return value

HRESULT

## See also

[CWiauPropertyList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nl-wiautil-cwiaupropertylist)

[CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty)

[CWiauPropertyList::SendToWia](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-sendtowia)