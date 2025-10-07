# EdpGetPrimaryIdentityIfManaged function

> [!NOTE]
> Starting in July 2022, Microsoft is deprecating Windows Information Protection (WIP) and the APIs that support WIP. Microsoft will continue to support WIP on supported versions of Windows. New versions of Windows won't include new capabilities for WIP, and it won't be supported in future versions of Windows. For more information, see [Announcing sunset of Windows Information Protection](https://techcommunity.microsoft.com/t5/windows-it-pro-blog/announcing-the-sunset-of-windows-information-protection-wip/ba-p/3579282).
>
> For your data protection needs, Microsoft recommends that you use [Microsoft Purview Information Protection](https://learn.microsoft.com/microsoft-365/compliance/information-protection) and [Microsoft Purview Data Loss Prevention](https://learn.microsoft.com/microsoft-365/compliance/dlp-learn-about-dlp). Purview simplifies the configuration set-up and provides an advanced set of capabilities.

In the presence of WIP policy, returns the primary WIP identity associated with an identity (protected domains configured in Intune).

## Parameters

### identity

Identity to get the primary identity for.

### primaryIdentity

Returned primary identity. Must be freed with [HeapFree](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapfree).

## Return value

An HRESULT value.

## Remarks

For example, if exchange.contoso.com is configured as a protected domain in WIP policy in Intune, this API will return the corporate identity configured for the same WIP policy in Intune.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------|
| Minimum supported client | Windows 10 |
| Minimum supported server | Windows 10 |
| Header | None |
| DLL | edputil.dll |

