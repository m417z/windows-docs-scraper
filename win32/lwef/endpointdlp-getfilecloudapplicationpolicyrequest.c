struct GetFileCloudApplicationPolicyRequest
{
    _Field_z_ LPCWSTR filePath;
    _Field_z_ LPCWSTR cloudAppDomainName;
    _Field_z_ LPCWSTR url;
    DlpEnforcementLevel* enforcementLevel;
    DlpSerializedBuffer policyInfo;`
};