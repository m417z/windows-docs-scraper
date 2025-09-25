# IMSCEPSetup::GetMSCEPSetupProperty

## Description

The **GetMSCEPSetupProperty** method gets a property value for a Network Device Enrollment Service (NDES) configuration.

## Parameters

### `propertyId` [in]

A value of the [MSCEPSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-mscepsetupproperty) enumeration that specifies the type of property to get.

### `pVal` [out]

A **VARIANT** that specifies the property value. The **VARIANT** type depends on the property type. For more information about the **VARIANT** type, see [MSCEPSetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-mscepsetupproperty).

## See also

[IMSCEPSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-imscepsetup)