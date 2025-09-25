# CWiauPropertyList::SetCurrentValue(INT,PSYSTEMTIME) (wiautil.h)

## Description

The **CWiauPropertyList::SetCurrentValue(INT,PSYSTEMTIME)** method sets the current value of a property of type **SYSTEMTIME**, and sets its type to VT_UI2 | VT_VECTOR.

## Parameters

### `index`

Specifies the property index. Set this parameter to the value in **pIdx* when the [CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty) method returns.

### `value`

Pointer to a memory location containing the value that is written to the device property in the property list. This pointer must remain valid until the [CWiauPropertyList::SendToWia](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-sendtowia) method is called.

## Remarks

The **SYSTEMTIME** structure is described in the Microsoft Windows SDK documentation.

## See also

[CWiauPropertyList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nl-wiautil-cwiaupropertylist)

[CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty)

[CWiauPropertyList::SendToWia](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-sendtowia)