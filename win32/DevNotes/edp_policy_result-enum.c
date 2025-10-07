typedef enum
{
    EdpPolicyResult_Unknown = 0,
    EdpPolicyResult_Allowed,
    EdpPolicyResult_Blocked,
    EdpPolicyResult_ConsentRequired,
    EdpPolicyResult_ConsentRequired_Add_Encryption,
    EdpPolicyResult_MaxValue
} EDP_POLICY_RESULT;