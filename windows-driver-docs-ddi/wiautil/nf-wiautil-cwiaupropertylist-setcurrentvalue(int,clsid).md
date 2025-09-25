# CWiauPropertyList::SetCurrentValue(INT,CLSID) (wiautil.h)

## Description

The **CWiauPropertyList::SetCurrentValue(INT,CLSID)** method sets the current value of a property of type **CLSID**, and sets its type to VT_CLSID.

## Parameters

### `index`

Specifies the property index. Set this parameter to the value in *_pIdx_ when the [CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty) method returns.

### `pValue`

Pointer to a memory location containing the value that is written to the device property in the property list. This pointer must remain valid until the [CWiauPropertyList::SendToWia](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-sendtowia) method is called.

## See also

[CWiauPropertyList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nl-wiautil-cwiaupropertylist)

[CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty)

[CWiauPropertyList::SendToWia](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-sendtowia)