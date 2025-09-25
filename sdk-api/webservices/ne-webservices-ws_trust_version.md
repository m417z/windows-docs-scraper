# WS_TRUST_VERSION enumeration

## Description

Defines the WS-Trust specification version to be used with message
security and mixed-mode security.

## Constants

### `WS_TRUST_VERSION_FEBRUARY_2005:0x1`

WS-Trust with the specification URI of `http://schemas.xmlsoap.org/ws/2005/02/trust`.

### `WS_TRUST_VERSION_1_3:0x2`

WS-Trust 1.3 with the specification URI of `http://docs.oasis-open.org/ws-sx/ws-trust/200512`.

## Remarks

Windows 7 and Windows Server 2008 R2: WWSAPI only supports [Ws-Trust](http://specs.xmlsoap.org/ws/2005/02/trust/WS-Trust.pdf) and [Ws-SecureConversation](http://specs.xmlsoap.org/ws/2005/02/sc/WS-SecureConversation.pdf) as defined by [Lightweight Web Services Security Profile (LWSSP)](https://learn.microsoft.com/openspecs/windows_protocols/ms-lwssp/376af2f8-f4fe-4577-bfd5-370ac12cac2e). For details regarding Microsoft's implementation please see the [MESSAGE Syntax](https://learn.microsoft.com/openspecs/windows_protocols/ms-lwssp/d4f0f509-e14a-47b5-81e8-ade06a51d1ed) section of LWSSP.