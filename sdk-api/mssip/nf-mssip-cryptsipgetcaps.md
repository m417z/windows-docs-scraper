# CryptSIPGetCaps function

## Description

The **CryptSIPGetCaps** function retrieves the capabilities of a [subject interface package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIP).

## Parameters

### `pSubjInfo` [in]

Pointer to a [SIP_SUBJECTINFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_subjectinfo) structure that specifies subject information data to the SIP APIs.

### `pCaps` [in, out]

Pointer to a [SIP_CAP_SET](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_cap_set_v2) structure that defines the capabilities of an SIP.

## Remarks

Unlike other SIP functions, [SIP_DISPATCH_INFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_dispatch_info) structure. Instead, callers must map the object identifier (OID) to the function entry point.

## See also

[SIP_CAP_SET](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_cap_set_v2)

[SIP_SUBJECTINFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_subjectinfo)

[pCryptSIPGetCaps](https://learn.microsoft.com/windows/desktop/api/mssip/nc-mssip-pcryptsipgetcaps)