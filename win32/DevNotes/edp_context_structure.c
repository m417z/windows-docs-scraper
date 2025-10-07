typedef struct
{
    EDP_CONTEXT_STATES contextStates;
    ULONG allowedEnterpriseIdCount;
    PWSTR enterpriseIdForUIEnforcement;
    PWSTR allowedEnterpriseIds[1];
} EDP_CONTEXT;