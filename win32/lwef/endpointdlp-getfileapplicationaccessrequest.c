struct GetFileApplicationAccessRequest
{
    _Field_z_ LPCWSTR filePath;
    _Field_z_ LPCWSTR applicationName;
    BOOLEAN* isRestrictedBrowserApp;
    DWORD* numOfActions;
    _Field_size_(*numOfActions) DlpAction* actions;
    DlpSerializedBuffer policyInfo;
};