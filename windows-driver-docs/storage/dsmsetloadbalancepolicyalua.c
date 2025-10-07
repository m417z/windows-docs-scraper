void DsmSetLoadBalancePolicyALUA(
   [in, Description("New Load Balance policy to be set"):amended] DSM_Load_Balance_Policy_V2 LoadBalancePolicy,
   [out, Description("Status of the operation"):amended] uint32                              Status
);