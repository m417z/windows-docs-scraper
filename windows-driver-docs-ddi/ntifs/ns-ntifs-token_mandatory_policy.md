## Description

The **TOKEN_MANDATORY_POLICY** structure specifies the mandatory integrity policy for a token.

## Members

### `Policy`

The mandatory integrity access policy for the associated token. This can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| TOKEN_MANDATORY_POLICY_OFF (0x0) | No mandatory integrity policy is enforced for the token. |
| TOKEN_MANDATORY_POLICY_NO_WRITE_UP (0x1) | A process associated with the token cannot write to objects that have a greater mandatory integrity level. |
| TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN (0x2) | A process created with the token has an integrity level that is the lesser of the parent-process integrity level and the executable-file integrity level. |
| TOKEN_MANDATORY_POLICY_VALID_MASK (0x3) | A combination of TOKEN_MANDATORY_POLICY_NO_WRITE_UP and TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN. |

## See also

[**TOKEN_ACCESS_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-token_access_information)