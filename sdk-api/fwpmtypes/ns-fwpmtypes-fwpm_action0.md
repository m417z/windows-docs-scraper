# FWPM_ACTION0 structure

## Description

The **FWPM_ACTION0** structure specifies the action taken if all the filter conditions are true.

## Members

### `type`

Action type as specified by **FWP_ACTION_TYPE** which maps to a **UINT32**.

Possible values:

| Value | Meaning |
| --- | --- |
| **FWP_ACTION_BLOCK** | Block the traffic. <br><br>0x00000001 | FWP_ACTION_FLAG_TERMINATING |
| **FWP_ACTION_PERMIT** | Permit the traffic.<br><br>0x00000002 | FWP_ACTION_FLAG_TERMINATING |
| **FWP_ACTION_CALLOUT_TERMINATING** | Invoke a callout that always returns block or permit.<br><br>0x00000003 | FWP_ACTION_FLAG_CALLOUT | FWP_ACTION_FLAG_TERMINATING |
| **FWP_ACTION_CALLOUT_INSPECTION** | Invoke a callout that never returns block or permit.<br><br>0x00000004 | FWP_ACTION_FLAG_CALLOUT | FWP_ACTION_FLAG_NON_TERMINATING |
| **FWP_ACTION_CALLOUT_UNKNOWN** | Invoke a callout that may return block or permit.<br><br>0x00000005 | FWP_ACTION_FLAG_CALLOUT |

### `filterType`

An arbitrary GUID chosen by the policy provider.

Available when the action does not invoke a callout, that is, **type** does not contain **FWP_ACTION_FLAG_CALLOUT**.

### `calloutKey`

The GUID for a valid callout in the layer.

Available when the action invokes a callout, that is, **type** contains **FWP_ACTION_FLAG_CALLOUT**.

### `bitmapIndex`

## Remarks

**FWPM_ACTION0** is a specific implementation of FWPM_ACTION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)