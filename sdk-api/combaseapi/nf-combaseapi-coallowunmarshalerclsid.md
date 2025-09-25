# CoAllowUnmarshalerCLSID function

## Description

Adds an unmarshaler CLSID to the allowed list for the calling process only.

## Parameters

### `clsid` [in]

The CLSID of the unmarshaler to be added to the per-process allowed list.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Don't call the **CoAllowUnmarshalerCLSID** function until after [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity) has been called in the current process.

The **CoAllowUnmarshalerCLSID** function provides more granular control over unmarshaling policy than is provided by the policy options. If the process applies any unmarshaling policy, the effect of the **CoAllowUnmarshalerCLSID** function is to make the policy comparatively weaker. For this reason, only call **CoAllowUnmarshalerCLSID** when the security impact is well understood. Usually, this is used to facilitate applying a stronger unmarshaling policy option for the broad attack surface reduction this provides, when a specific unmarshaler CLSID not allowed by that option is needed due to other constraints.

For example, it's appropriate to call the **CoAllowUnmarshalerCLSID** function when an unmarshaler is known or believed to have a vulnerability but is required by an app. Also, it's appropriate to call **CoAllowUnmarshalerCLSID** if the unmarshaler is used in multiple processes, but only as part of an uncommon feature. Don't use the **CoAllowUnmarshalerCLSID** function as a replacement for hardening the unmarshaler.

## See also

[GLOBALOPT_UNMARSHALING_POLICY_VALUES](https://learn.microsoft.com/windows/win32/api/objidl/ne-objidl-globalopt_unmarshaling_policy_values)

[IMarshalingStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshalingstream)