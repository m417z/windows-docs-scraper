# _WIA_PROPERTY_CONTEXT structure

## Description

The **WIA_PROPERTY_CONTEXT** structure stores property identifiers and their context.

## Members

### `cProps`

Specifies the number of property identifiers stored in this structure.

### `pProps`

Is an array of property identifiers that indicate the properties being written.

### `pChanged`

Is an array of Boolean values indicating which properties are changing. A member of this array is **TRUE** if the corresponding property is changing, and **FALSE** if the corresponding property is not changing. That is, if **pChanged**[n] is **TRUE**, **pProps**[n] will be changed, and if **pChanged**[n] is **FALSE**, **pProps**[n] will not be changed.

## Remarks

The Boolean values indicate whether the corresponding property is being written (changed) by an application calling [**IPropertyStorage::WriteMultiple**](https://learn.microsoft.com/windows/win32/api/propidl/nf-propidl-ipropertystorage-writemultiple).

Several WIA service library functions use the WIA_PROPERTY_CONTEXT structure. The [wiasCreatePropContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiascreatepropcontext) and [wiasFreePropContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasfreepropcontext) functions use it when a property context is created or freed. The [wiasIsPropChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasispropchanged) and [wiasSetPropChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetpropchanged) use this structure to determine whether a property changed, and to modify a property context when the property does change. The **wiasGetChangedValue***Xxx* functions use this structure to determine whether a property of a certain type has changed. The [wiasUpdateValidFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasupdatevalidformat) and [wiasUpdateScanRect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasupdatescanrect) use it to, respectively, update a property context and to update the scanning area sizes for a scanning device.

## See also

[wiasCreatePropContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiascreatepropcontext)

[wiasFreePropContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasfreepropcontext)

[wiasGetChangedValueFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvaluefloat)

[wiasGetChangedValueGuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvalueguid)

[wiasGetChangedValueLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvaluelong)

[wiasGetChangedValueStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasgetchangedvaluestr)

[wiasIsPropChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasispropchanged)

[wiasSetPropChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiassetpropchanged)

[wiasUpdateScanRect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasupdatescanrect)

[wiasUpdateValidFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasupdatevalidformat)