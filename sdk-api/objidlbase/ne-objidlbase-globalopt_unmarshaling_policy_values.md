# GLOBALOPT_UNMARSHALING_POLICY_VALUES enumeration

## Description

Provides values for the COM unmarshaling policy global option.

## Constants

### `COMGLB_UNMARSHALING_POLICY_NORMAL:0`

Unmarshaling behavior is the same as versions older than Windows 8. **EOAC_NO_CUSTOM_MARSHAL** restrictions apply if this flag is set in [CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity). Otherwise, there are no restrictions. This is the default for processes that aren't in the app container.

### `COMGLB_UNMARSHALING_POLICY_STRONG:1`

Unmarshaling allows only a system-trusted list of hardened unmarshalers and unmarshalers allowed per-process by the [CoAllowUnmarshalerCLSID](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coallowunmarshalerclsid) function. This is the default for processes in the app container.

### `COMGLB_UNMARSHALING_POLICY_HYBRID:2`

Unmarshaling data whose source is app container allows only a system-trusted list of hardened unmarshalers and unmarshalers allowed per-process by the [CoAllowUnmarshalerCLSID](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coallowunmarshalerclsid) function. Unmarshaling behavior for data with a source that's not app container is unchanged from previous versions.

## See also

[IGlobalOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iglobaloptions)

[IMarshalingStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshalingstream)