# _DSM_QuerySupportedLBPolicies_V2 structure

## Description

The DSM_QuerySupportedLBPolicies_V2 structure is used to query the list of load balance policies that are supported on the LUN. It is basically the same as the DSM_QuerySupportedLBPolicies except that it passes back the supported policies as an array of DSM_Load_Balance_Policy_V2 structures instead of DSM_Load_Balance_Policy structures. The caller must direct the WMI call for querying to a pseudo-LUN that is addressed by the WMI instance name that corresponds to the pseudo-LUN. All DSMs must register and implement this class, even if they do not support any load balance policies for the devices they control.

## Members

### `SupportedLBPoliciesCount`

An unsigned 32-bitfield that returns the number of load balance policies that are supported for the LUN by the controlling DSM.

### `Reserved`

Should be zero.

### `Supported_LB_Policies`

An array of DSM_Load_Balance_Policy_V2 structures, one for each of the supported load balance policies. The number of array elements will be the same as *SupportedLBPoliciesCount*. Each element of the array lists the supported load balance policy type. It is not expected that the element return path specifics.