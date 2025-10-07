struct SendOperationEnforcementEventRequest
{
    _Field_z_ LPCWSTR source;
    _Field_z_ LPCWSTR target;
    _Field_z_ LPCWSTR actionType;
    DlpSerializedBuffer policyInfo;
    DlpEnforcementLevel enforcementLevel;
    BOOLEAN userBypass;
    _Field_z_ LPCWSTR businessJustification;
    _Field_z_ LPCWSTR printerOutputFileName;
    _Field_z_ LPCWSTR printerName;
    _Field_z_ LPCWSTR printerJobName;
    _Field_z_ LPCWSTR overrideInfoJson;
};