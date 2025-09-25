# INetFwRules::Add

## Description

The **Add** method adds a new rule to the collection.

## Parameters

### `rule` [in]

Rule to be added to the collection via an [INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule) object.

## Return value

### C++

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed because a parameter was not valid. |
| **E_UNEXPECTED** | The method failed because the object is already in the collection. |

### VB

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed because a parameter was not valid. |
| **E_UNEXPECTED** | The method failed because the object is already in the collection. |

## Remarks

If a rule with the same rule identifier as the one being submitted already exists, the existing rule is overwritten.

Adding a firewall rule with a [LocalAppPackageId](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwrule3-get_localapppackageid) specified can lead to unexpected behavior and is not supported.

## See also

[INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule)

[INetFwRules](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrules)