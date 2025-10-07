# WINBIO\_ACCOUNT\_POLICY structure

The **WINBIO\_ACCOUNT\_POLICY** structure contains either a default or account-specific antispoofing policy.

## Members

**Identity**

A [**WINBIO\_IDENTITY**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-identity) structure that specifies the account information.

**AntiSpoofBehavior**

One of the [**WINBIO\_ANTI\_SPOOF\_POLICY\_ACTION**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-anti-spoof-policy-action) enumeration values that specifies what antispoofing policy action to use for the account.

## Remarks

See the discussion of the [**EngineAdapterSetAccountPolicy**](https://learn.microsoft.com/windows/desktop/api/Winbio_adapter/nc-winbio_adapter-pibio_engine_set_account_policy_fn) method for a description of how this structure is used.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\]<br> |
| Header<br> | Winbio\_adapter.h (include Winbio\_adapter.h) |

