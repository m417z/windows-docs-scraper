# IFhTarget::GetNumericalProperty

## Description

Retrieves a numeric property of the File History backup target that is represented by an [IFhTarget](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhtarget) interface.

> [!NOTE]
> **IFhTarget** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `PropertyType` [in]

Specifies the numeric property. See the [FH_TARGET_PROPERTY_TYPE](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_target_property_type) enumeration for a list of possible numeric properties.

### `PropertyValue` [out]

Receives the value of the numeric property.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code such as one of the values defined in the FhErrors.h header file.

## Remarks

The [FH_TARGET_PROPERTY_TYPE](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_target_property_type) enumeration defines property types for string properties and numeric properties. However, the **IFhTarget::GetNumericalProperty** method can only be used to retrieve numeric properties. String properties must be retrieved by calling the [IFhTarget::GetStringProperty](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhtarget-getstringproperty) method.

## See also

[FH_TARGET_PROPERTY_TYPE](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_target_property_type)

[IFhTarget](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhtarget)

[IFhTarget::GetStringProperty](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhtarget-getstringproperty)