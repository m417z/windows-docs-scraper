# IFhTarget::GetStringProperty

## Description

Retrieves a string property of the File History backup target that is represented by an [IFhTarget](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhtarget) interface.

> [!NOTE]
> **IFhTarget** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `PropertyType` [in]

Specifies the string property. See the [FH_TARGET_PROPERTY_TYPE](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_target_property_type) enumeration for the list of possible string property types.

### `PropertyValue` [out]

This parameter must be **NULL** on input. On output, it receives a pointer to a string that contains the string property. This string is allocated by calling [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). You must call [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the string when it is no longer needed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code such as one of the values defined in the FhErrors.h header file.

## Remarks

The [FH_TARGET_PROPERTY_TYPE](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_target_property_type) enumeration defines property types for string properties and numeric properties. However, the **IFhTarget::GetStringProperty** method can only be used to retrieve string properties. Numeric properties must be retrieved by calling the [IFhTarget::GetNumericalProperty](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhtarget-getnumericalproperty) method.

## See also

[FH_TARGET_PROPERTY_TYPE](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_target_property_type)

[IFhTarget](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhtarget)

[IFhTarget::GetNumericalProperty](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhtarget-getnumericalproperty)