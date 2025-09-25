# IPropertyEnumType::GetEnumType

## Description

Gets an enumeration type from an enumeration information structure.

## Parameters

### `penumtype` [out]

Type: **PROPENUMTYPE***

When this method returns, contains a pointer to one of the values listed below that indicate the enumeration type.

#### PET_DISCRETEVALUE (0)

Use [GetDisplayText](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertyenumtype-getdisplaytext) and either [GetRangeMinValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertyenumtype-getrangeminvalue) or [GetRangeSetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertyenumtype-getrangesetvalue).

#### PET_RANGEDVALUE (1)

Use [GetDisplayText](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertyenumtype-getdisplaytext) and either [GetRangeMinValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertyenumtype-getrangeminvalue) or [GetRangeSetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertyenumtype-getrangesetvalue).

#### PET_DEFAULTVALUE (2)

Use [GetDisplayText](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertyenumtype-getdisplaytext).

#### PET_ENDRANGE (3)

Use [GetValue](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nf-gdipluscolor-color-getvalue) or [GetRangeMinValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertyenumtype-getrangeminvalue).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For additional information, see [enumeratedList](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-enumeratedlist).