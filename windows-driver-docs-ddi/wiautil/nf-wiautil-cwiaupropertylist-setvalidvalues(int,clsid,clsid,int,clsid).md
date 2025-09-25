# CWiauPropertyList::SetValidValues(INT,CLSID,CLSID,INT,CLSID) (wiautil.h)

## Description

The **CWiauPropertyList::SetValidValues(INT,CLSID,CLSID,INT,CLSID)** method sets the type, as well as default, current, and valid values for a **CLSID** property associated with a list of values. The method also sets the property type to VT_CLSID and subtype to WIA_PROP_LIST.

## Parameters

### `index`

Specifies the property index. Set this parameter to the value in *_pIdx_ when the [CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty) method returns.

### `defaultValue`

Specifies the default setting of the property on the device.

### `currentValue`

Specifies the current setting of the property on the device.

### `numValues`

Specifies the number of values in the property list.

### `pValues`

Pointer to a memory location that contains the address of the first property in the property list. This pointer must remain valid until the [CWiauPropertyList::SendToWia](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-sendtowia) method is called.

## See also

[CWiauPropertyList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nl-wiautil-cwiaupropertylist)

[CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty)

[CWiauPropertyList::SendToWia](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-sendtowia)