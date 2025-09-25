# ICertSrvSetup::GetSupportedCATypes

## Description

The **GetSupportedCATypes** method gets the types of [certification authorities](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CAs) that can be installed on a computer under the caller context. This method does not change the state of the **CCertSrvSetup** object.

## Parameters

### `pCATypes` [out]

A pointer to a **VARIANT** array of **VT_UI4** types that specify the supported CAs. The [ENUM_CATYPES](https://learn.microsoft.com/windows/desktop/api/certsrv/ne-certsrv-enum_catypes) enumeration specifies the possible values for the array.

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)