# pCryptSIPGetCaps callback function

## Description

The **pCryptSIPGetCaps** function is implemented by an [subject interface package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIP) to report capabilities.

## Parameters

### `pSubjInfo` [in]

Pointer to a [SIP_SUBJECTINFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_subjectinfo) structure that specifies subject information data to the SIP APIs.

### `pCaps` [in, out]

Pointer to a [SIP_CAP_SET](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_cap_set_v2) structure that defines the capabilities of an SIP.

## See also

[CryptSIPGetCaps](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipgetcaps)

[SIP_CAP_SET](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_cap_set_v2)

[SIP_SUBJECTINFO](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_subjectinfo)