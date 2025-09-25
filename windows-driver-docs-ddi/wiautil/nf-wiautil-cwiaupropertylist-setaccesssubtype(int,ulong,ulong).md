# CWiauPropertyList::SetAccessSubType(INT,ULONG,ULONG)

## Description

The **CWiauPropertyList::SetAccessSubType(INT,ULONG,ULONG)** method resets a property's access and subtype.

## Parameters

### `index`

Specifies the property's index in the property list.

### `Access`

Specifies the type of access for the property, usually either WIA_PROP_READ (read-only) or WIA_PROP_RW (read/write).

### `SubType`

Specifies the property subtype, one of WIA_PROP_FLAG, WIA_PROP_LIST, WIA_PROP_RANGE, or WIA_PROP_NONE. The first three constants indicate, respectively, that a property is a set of flag values, a list of values, or a range of values. The fourth constant indicates that a property is none of these.

## Return value

This method returns an NTSTATUS value.

## Remarks

A property's access and subtype are set originally in a call to the [CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty) method.

## See also

[CWiauPropertyList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nl-wiautil-cwiaupropertylist)

[CWiauPropertyList::DefineProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiaupropertylist-defineproperty)