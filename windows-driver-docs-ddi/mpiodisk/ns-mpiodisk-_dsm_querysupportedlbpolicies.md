# _DSM_QuerySupportedLBPolicies structure

## Description

The DSM_QuerySupportedLBPolicies structure is used to query the list of load balance policies that are supported on the LUN.

## Members

### `SupportedLBPoliciesCount`

An unsigned 32-bitfield that returns the number of policies that are supported for the LUN by the controlling DSM.

### `Reserved`

Should be zero.

### `Supported_LB_Policies`

An array of DSM_Load_Balance_Policy structures, one for each of the supported load balance policies. The number of array elements will be the same as *SupportedLBPoliciesCount*. Each element of the array lists only the supported load balance policy type.