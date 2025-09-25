# _DSM_QueryLBPolicy_V2 structure

## Description

The DSM_QueryLBPolicy_V2 structure is used to query a LUN's current load balance policy. It is basically the same as the DSM_QueryLBPolicy structure except that it returns the load balance information by using the DSM_Load_Balance_Policy_V2 structure.

## Members

### `LoadBalancePolicy`

An instance of the DSM_Load_Balance_Policy_V2 structure that has information about the current load balance policy that is being applied by the DSM on the targeted pseudo-LUN.