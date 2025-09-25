# SL_AD_ACTIVATION_INFO structure

## Description

Specifies information used for the retail or Active Directory phone activation of a license.

## Members

### `header`

 An [SL_ACTIVATION_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/slpublic/ns-slpublic-sl_activation_info_header) structure that contains the activation type. The activation type determines whether the **SL_AD_ACTIVATION_INFO** structure is used for retail or Active Directory phone activation.

### `pwszProductKey`

The product key.

### `pwszActivationObjectName`

The name of the activation object.

## Remarks

For an example of how this structure is used, see the description of the *pActivationInfo* parameter in the [SLActivateProduct](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slactivateproduct), [SLDepositOfflineConfirmationIdEx](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-sldepositofflineconfirmationidex), and [SLGenerateOfflineInstallationIdEx](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slgenerateofflineinstallationidex) functions.

## See also

[SLActivateProduct](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slactivateproduct)

[SLDepositOfflineConfirmationIdEx](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-sldepositofflineconfirmationidex)

[SLGenerateOfflineInstallationIdEx](https://learn.microsoft.com/windows/desktop/api/slpublic/nf-slpublic-slgenerateofflineinstallationidex)

[SL_ACTIVATION_INFO_HEADER](https://learn.microsoft.com/windows/desktop/api/slpublic/ns-slpublic-sl_activation_info_header)

[SL_ACTIVATION_TYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sl_activation_type)