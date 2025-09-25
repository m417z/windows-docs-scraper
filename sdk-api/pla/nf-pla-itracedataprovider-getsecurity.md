# ITraceDataProvider::GetSecurity

## Description

Retrieves the security information for the trace data provider.

## Parameters

### `SecurityInfo` [in]

The object-related security information. For details, see the [SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) data type.

### `Sddl` [out]

A string that describes the security descriptor for the object. For details, see [Security Descriptor Definition Language](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-string-format).

## Return value

Returns S_OK if successful.

## See also

[ITraceDataProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedataprovider)

[ITraceDataProvider::SetSecurity](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovider-setsecurity)