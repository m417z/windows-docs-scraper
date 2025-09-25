# ICertSrvSetup::GetCASetupProperty

## Description

The **GetCASetupProperty** method gets a property value for a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) configuration.

## Parameters

### `propertyId` [in]

A value of the [CASetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-casetupproperty) enumeration that specifies the type of property to get.

### `pPropertyValue` [out]

A **VARIANT** value that specifies the property value. The **VARIANT** type depends on the property type. For more information about the **VARIANT** type, see [CASetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-casetupproperty).

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)