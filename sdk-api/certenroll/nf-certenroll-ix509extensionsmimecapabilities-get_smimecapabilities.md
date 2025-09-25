# IX509ExtensionSmimeCapabilities::get_SmimeCapabilities

## Description

The **SmimeCapabilities** property retrieves a collection of [ISmimeCapability](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ismimecapability) objects.

This property is read-only.

## Parameters

## Remarks

Call the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionsmimecapabilities-initializeencode) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionsmimecapabilities-initializedecode) method to initialize the **SMIMECapabilities** extension. You can also call the [Critical](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_critical) property to specify and retrieve a Boolean value that identifies whether the extension is critical, and you can call the [ObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extension-get_objectid) property to retrieve the OID associated with the extension.

## See also

[IX509ExtensionSmimeCapabilities](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsmimecapabilities)