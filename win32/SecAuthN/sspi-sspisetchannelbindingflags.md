# SspiSetChannelBindingFlags function

The **SspiSetChannelBindingFlags** function is exposed in both kernel and user mode drivers of SspiCli. This helps the server side to fetch the channel bindings from query attributes and convert it to the **ChannelBindingsEX** buffer format and set the Audit flags before passing it to the **SSPCommon** for validation during the ASC Call. Thus, EPA Audit can be enabled/disabled.

## Parameters

*\*pBindings* `[InOut]`

The channel bindings to be set.

*flags* `[in]`

The flags to be set, indicating your desired configuration.

## Return value

Returns **SEC_E_OK** if the function succeeds; otherwise, returns a nonzero error code.

## Requirements

| Requirement | Value |
|--------|--------|
| Minimum supported client | Not supported |
| Minimum supported server | Windows Server 2019<br>Windows Server 2022<br>Windows Server 23H2 |
| Header | Sspi.h |

## See also

[Supporting Extended Protection for Authentication (EPA) in a service](https://learn.microsoft.com/windows/win32/secauthn/epa-support-in-service)

[SecPkgContext_Bindings](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-secpkgcontext_bindings)