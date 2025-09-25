# ICertSrvSetup::SetCASetupProperty

## Description

The **SetCASetupProperty** method sets a property value for a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) configuration.

## Parameters

### `propertyId` [in]

A [CASetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-casetupproperty) constant that specifies the type of property to configure.

The following properties are set as a side effect of other methods and cannot be set directly with this method.

**ENUM_SETUPPROP_CANAME**
**ENUM_SETUPPROP_CADSSUFFIX**
**ENUM_SETUPPROP_EXPIRATIONDATE**
**ENUM_SETUPPROP_PARENTCANAME**
**ENUM_SETUPPROP_PARENTCAMACHINE**
**ENUM_SETUPPROP_DATABASEDIRECTORY**
**ENUM_SETUPPROP_LOGDIRECTORY**
**ENUM_SETUPPROP_SHAREDFOLDER**
**ENUM_SETUPPROP_WEBCAMACHINE**
**ENUM_SETUPPROP_WEBCANAME**

### `pPropertyValue` [in]

A pointer to a **VARIANT** that specifies the property value. The **VARIANT** type depends on the property type. For more information about the **VARIANT** type, see [CASetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-casetupproperty).

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)