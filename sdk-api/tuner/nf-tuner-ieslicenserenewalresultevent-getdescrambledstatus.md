# IESLicenseRenewalResultEvent::GetDescrambledStatus

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a code from a [LicenseRenewalResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieslicenserenewalresultevent) event that indicates the result of an attempt to descramble protected content.

## Parameters

### `pDescrambledStatus` [out, retval]

Receives a status code that indicates the descrambling status.

| Value | Meaning |
| --- | --- |
| 0x00000000 | Free to air content (nonprotected). |
| 0x00000001 | Descrambling possible. |
| 0x80010000 | No technical (other). |
| 0x80010001 | (No technical) firmware upgrade required. |
| 0x80010002 | (No technical) internal failure. |
| 0x80010003 | (No technical) initializing/not ready. |
| 0x80010004 | (No technical) setup required. |
| 0x80010005 | (No technical) no access card. |
| 0x80010006 | (No technical) access card failure. |
| 0x80010007 | (No technical) bad access card. |
| 0x80010008 | (No technical) wrong access card. |
| 0x80010009 | (No technical) expired access card. |
| 0x8001000A | (No technical) out of resources, for example, too many streams. |
| 0x8001000B | (No technical) not in purchase window. |
| 0x8001000C | (No technical) not in purchase window, prior. |
| 0x8001000D | (No technical) not in purchase window, after. |
| 0x80020000 | No entitlement (other). |
| 0x80020001 | (No entitlement) access card not authorized. |
| 0x80020002 | (No entitlement) service not authorized. |
| 0x80020003 | (No entitlement) service expired. |
| 0x80020004 | (No entitlement) account not authorized. |
| 0x80020005 | (No entitlement) account expired. |
| 0x80020006 | (No entitlement) service blacked out. |
| 0x80020007 | (No entitlement) purchase required. |
| 0x80020008 | (No entitlement) insufficient credit. |
| 0x80020009 | (No entitlement) purchase canceled. |
| 0x8002000A | (No entitlement) renewal entitlement expired. |
| 0x8002000B | (No entitlement) showing not available. |
| 0x8002000C | (No entitlement) showing next. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESLicenseRenewalResultEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ieslicenserenewalresultevent)