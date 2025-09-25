# IDPE_ATTR structure

## Description

The **IDPE_ATTR** structure contains identity policy element attribute information.

## Members

### `PeAttribLength`

Length of the entire **IDPE_ATTR** structure, in bytes.

### `PeAttribType`

Policy element attribute type. Must be the following type:

| Value | Meaning |
| --- | --- |
| **PE_ATTRIB_TYPE_POLICY_LOCATOR** | Policy locator type. |

### `PeAttribSubType`

Policy element attribute subtype. Must be the following type:

| Value | Meaning |
| --- | --- |
| **POLICY_LOCATOR_SUB_TYPE_ASCII_DN** | The sub type is ASCII. |
| **POLICY_LOCATOR_SUB_TYPE_UNICODE_DN** | The sub type is UNICODE. |
| **POLICY_LOCATOR_SUB_TYPE_ASCII_DN_ENC** | The sub type is encoded ASCII. |
| **POLICY_LOCATOR_SUB_TYPE_UNICODE_DN_ENC** | The sub type is encoded UNICODE. |

### `PeAttribValue`

Policy element value.

## See also

[Policy Elements](https://learn.microsoft.com/previous-versions/windows/desktop/qos/policy-elements)