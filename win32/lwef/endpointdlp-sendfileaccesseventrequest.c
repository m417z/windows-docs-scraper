struct SendFileAccessEventRequest
{
    _Field_z_ LPCWSTR filePath;
    _Field_z_ LPCWSTR url;
    DlpSerializedBuffer policyInfo;
    DlpEnforcementLevel enforcementLevel;
    BOOLEAN userBypass;
    _Field_z_ LPCWSTR businessJustification;
};