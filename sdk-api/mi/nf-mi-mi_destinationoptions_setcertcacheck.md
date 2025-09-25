# MI_DestinationOptions_SetCertCACheck function

## Description

Enables or disables the CA certificate check for an SSL transport.

## Parameters

### `options` [in, out]

A pointer to a [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from the [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions) function.

### `check`

Boolean value where **MI_TRUE** means to enable the certificate CA check and **MI_FALSE** means to disable it.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

If an SSL transport is not used, this setting is ignored. By default, the certificate CA check is carried out. This may need to be disabled if a self signed certificate is used on the server.