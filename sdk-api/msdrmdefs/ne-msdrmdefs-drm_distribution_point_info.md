# DRM_DISTRIBUTION_POINT_INFO enumeration

## Description

> [!NOTE]
> The AD RMS SDK leveraging functionality exposed by the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal), which leverages functionality exposed by the client in **Msipc.dll**.

The **DRM_DISTRIBUTION_POINT_INFO** enumeration specifies the type of distribution point to retrieve information about when calling [DRMGetIssuanceLicenseInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetissuancelicenseinfo).

## Constants

### `DRM_DISTRIBUTION_POINT_LICENSE_ACQUISITION`

Retrieves information about the default end-user license acquisition URL contained in the issuance license. Use this constant to retrieve information about the silent intranet URL. The following example shows a license acquisition URL.

```xml
<DISTRIBUTIONPOINT>
  <OBJECT type="License-Acquisition-URL">
    <ID type="MS-GUID">
       {0045FD50-383B-43AA-90A4-ED013CD0CFE5}
    </ID>
    <NAME>Contoso Licensing Authority</NAME>
    <ADDRESS type="URL">
        http://Contoso.com/_wmcs/licensing
    </ADDRESS>
  </OBJECT>
</DISTRIBUTIONPOINT>
```

### `DRM_DISTRIBUTION_POINT_PUBLISHING`

Retrieves information about the issuance license signing service URL contained in the issuance license. The following example shows a signing service URL.

```xml
<DISTRIBUTIONPOINT>
  <OBJECT type="Publishing-URL">
    <ID type="MS-GUID">{9A23D98E-4449-4ba5-812A-F30808F3CB16}</ID>
    <NAME>Publishing Point</NAME>
    <ADDRESS type="URL">HTTP://petx64a526/_wmcs/licensing</ADDRESS>
  </OBJECT>
</DISTRIBUTIONPOINT>
```

### `DRM_DISTRIBUTION_POINT_REFERRAL_INFO`

Retrieves information about the nonsilent end-user license acquisition URL in the issuance license.

>[!Note]
>Beginning with RMS 1.0 SP1, nonsilent license acquisition is no longer supported.

```xml
<DISTRIBUTIONPOINT>
  <OBJECT type="Referral-Info">
    <ID type="MS-GUID">{81C42010-208A-4ABA-BAB6-C3C60F06DD5F}</ID>
    <NAME>Contoso Credit Card Splash Page</NAME>
    <ADDRESS type="URL">
       https://www.contoso.com/CreditCardOffers.htm
    </ADDRESS>
  </OBJECT>
</DISTRIBUTIONPOINT>
```

## See also

[AD RMS Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-enumerations)

[DRMGetIssuanceLicenseInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetissuancelicenseinfo)